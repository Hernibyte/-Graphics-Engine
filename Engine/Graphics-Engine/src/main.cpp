#include"Includes.h"

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f); // Posicion de la camara
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f); //  de la camara
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f); // Eje arriba

float deltaTime = 0.0f;
float lastFrame = 0.0f;

bool firstMouse = true;
float yaw = -90.0f;	// yaw se inicializa a -90.0 grados ya que una yaw de 0.0 da como resultado un vector de dirección que apunta hacia la derecha, por lo que inicialmente giramos un poco hacia la izquierda
float pitch = 0.0f;
float lastX = 800.0f / 2.0;
float lastY = 600.0 / 2.0;
float fov = 45.0f;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window); // detecta el input del teclado y setea
void mouse_callback(GLFWwindow* window, double xpos, double ypos); //detecta el input del mouse y setea
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset); //setea el tamaño del buffer

int main() {
	// Init Window --------------------
	glfwInit();

	GLFWwindow* window = glfwCreateWindow(800, 600, "HOLA MUNDO NUEVO", NULL, NULL);

	if (!window) { //verifica un correcto init
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window); //genera el contexto
	glfwSetCursorPosCallback(window, mouse_callback); //setea el input del cursor
	glfwSetScrollCallback(window, scroll_callback); //setea el input del scroll

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); // setea el input del teclado

	if (glewInit() != GLEW_OK) { // verifica un correcto init
		std::cout << "Fallo al inicializar GLEW" << std::endl;
		return -1;
	}

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); //setea el tamaño del frame buffer

	// --------------------
	glEnable(GL_DEPTH_TEST); //no me acuerdo que hace

	//---------------------

	float vertices[] = { //triangulos
		// positions         // colors
		//triangulo uno
		 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
		 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f,    // top 

		 //triangulo dos
		 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
		 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f,    // top 

		 //triangulo tres
		 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
		 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f,    // top 

		 //triangulo cuatro
		 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
		 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f,    // top 

		 //triangulo cinco
		 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
		 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top 
	};
	glm::vec3 trPositions[] = { //determina la posicion de los triagulos
		glm::vec3(1.0f,  1.6f,  0.0f),
		glm::vec3(2.0f,  5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f)
	};
	/*
	float vertices[] = { //genera un cuadrado
	 0.5f,  0.5f, 0.0f,  // top right
	 0.5f, -0.5f, 0.0f,  // bottom right
	-0.5f, -0.5f, 0.0f,  // bottom left
	-0.5f,  0.5f, 0.0f   // top left
	};
	unsigned int indices[] = {  // se usa junto con el drawelements para no superponer vertices
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};
	*/
	// Vertex Shader -------------------------
	const char* vertexShaderSource =
		"#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"layout (location = 1) in vec3 aColor;\n"
		"out vec3 ourColor;\n"
		"uniform mat4 model;\n"
		"uniform mat4 view;\n"
		"uniform mat4 projection;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = projection * view * model * vec4(aPos, 1.0);\n"
		"	ourColor = aColor;\n"
		"}\0";

	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	// verifica la compilacion del vertex
	int  success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	// Fragment Shader ------------------
	const char* fragmentShaderSource =
		"#version 330 core\n"
		"out vec4 FragColor;\n"
		"in vec3 ourColor;\n"
		"void main(){\n"
		"	FragColor = vec4(ourColor, 1.0);\n"
		"}\0";

	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	// Shader Program ---------------
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	// Delete Shaders ------------
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	// verifica la compilacion del programa
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
	}

	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// EBO ----------- El EBO se usa para el drawElements
	/*
	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	*/

	unsigned int modelLoc = glGetUniformLocation(shaderProgram, "model"); //se usa para determinarle al shader que se usara "model"
	unsigned int viewLoc = glGetUniformLocation(shaderProgram, "view"); // se usa para determinarle al shader que se usara "view"
	unsigned int projectionLoc = glGetUniformLocation(shaderProgram, "projection"); // se usa para determinarle al shader que se usara "projection"

	//render loop
	while (!glfwWindowShouldClose(window)) {

		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		//input
		processInput(window);

		//rendering commands here
		glClearColor(0.5f, 0.2f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//drawing code ---------------

		glm::mat4 view = glm::mat4(1.0f); // view es algo asi como la "camara"
		const float radius = 10.0f;
		float camX = sin(glfwGetTime()) * radius;
		float camZ = cos(glfwGetTime()) * radius;
		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp); // setea su posicion, no tengo la seguridad de como funciona internamente
		//view = glm::rotate(view, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));

		glm::mat4 projection; // setea la projeccion de la camara (podria ser prespective o orthographic)
		projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); //no se usa si no hay drawElements
		//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		// indica el uso del shaderProgram
		glUseProgram(shaderProgram);
		// dibuja el objeto
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view)); // toma el view y lo devuelve como un uniform hacia el shader
		glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));// toma el projection y lo devuelve como un uniform hacia el shader
		glBindVertexArray(VAO); // bindea el vao
		for (unsigned int i = 0; i < 5; i++) { //bucle para mostrar varios triangulos
			glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, trPositions[i]);
			float angle = 20.0f * i;
			vec = model * vec;
			model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

			glDrawArrays(GL_TRIANGLES, 0, 15);
		}
		//glDrawArrays(GL_TRIANGLES, 0, 3); // no va

		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // no va
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window, true);

	const float cameraSpeed = 0.01f;

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		cameraPos += cameraSpeed * cameraFront;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		cameraPos -= cameraSpeed * cameraFront;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
	if (firstMouse) {
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	float sensitivity = 0.1f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront = glm::normalize(front);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
	fov -= (float)yoffset;
	if (fov < 1.0f)
		fov = 1.0f;
	if (fov > 45.0f)
		fov = 45.0f;
}