#include"gamebase.h"

gamebase::gamebase() {
	glfwInit();
	transX = 0.0f;
	transY = 0.0f;
	transZ = 0.0f;
	rotateX = 0.0f;
	rotateY = 0.0f;
	rotateZ = 0.0f;
	scaleX = 1.0f;
	scaleY = 1.0f;
	scaleZ = 1.0f;
	win = new window();
	render = new renderer();
	Tr = new Shape(render, GL_TRIANGLES);
	Sprite = new sprite(render, GL_QUADS);
	Sprite2 = new sprite(render, GL_QUADS);
}

gamebase::~gamebase() {
	if (win != NULL) {
		delete win;
	}
	if (render != NULL) {
		delete render;
	}
	if (Tr != NULL) {
		delete Tr;
	}
	if (Sprite != NULL) {
		delete Sprite;
	}
	if (Sprite2 != NULL) delete Sprite2;
}

int gamebase::startEngine() {
	if (!glfwInit() || win == NULL) return -1;

	win->createWindowValidate();
	win->createContexCurrent();
	win->initGLEW();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//create VBO
	render->createVBO();
	//create Tr
	render->bindVBO(render->getVBO());
	render->setVertexAttrib();
	Sprite->setBufferData();
	Sprite2->setBufferData();
	//shader
	render->setShader();
	//Set texture
	render->generateTexture();
	render->setParameterTexture();
	//------
	glUseProgram(render->getShaderProgram());

	//------
	//Debug de bounds
	std::cout << "Sprite bounds" << std::endl;
	std::cout << "min.x: " << Sprite->getBounds().min.x << std::endl;
	std::cout << "min.y: " << Sprite->getBounds().min.y << std::endl;
	std::cout << "max.x: " << Sprite->getBounds().max.x << std::endl;
	std::cout << "max.y: " << Sprite->getBounds().max.y << std::endl;
	std::cout << "size.x: " << Sprite->getBounds().size.x << std::endl;
	std::cout << "size.y: " << Sprite->getBounds().size.y << std::endl;
	std::cout << std::endl;
	std::cout << "Sprite2 bounds" << std::endl;
	std::cout << "min.x: " << Sprite2->getBounds().min.x << std::endl;
	std::cout << "min.y: " << Sprite2->getBounds().min.y << std::endl;
	std::cout << "max.x: " << Sprite2->getBounds().max.x << std::endl;
	std::cout << "max.y: " << Sprite2->getBounds().max.y << std::endl;
	std::cout << "size.x: " << Sprite2->getBounds().size.x << std::endl;
	std::cout << "size.y: " << Sprite2->getBounds().size.y << std::endl;

	while (!win->detecWindowShouldClose()) {
		// Input

		if (glfwGetKey(win->getWin(), GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(win->getWin(), true);
		
		//transform

		if (glfwGetKey(win->getWin(), GLFW_KEY_W) == GLFW_PRESS)
		{
			transY += 0.01f;
			Sprite->translateBounds(0.0f, 0.01f);
		}
		if (glfwGetKey(win->getWin(), GLFW_KEY_S) == GLFW_PRESS)
		{
			transY -= 0.01f;
			Sprite->translateBounds(0.0f, -0.01f);
		}
		if (glfwGetKey(win->getWin(), GLFW_KEY_D) == GLFW_PRESS)
		{
			transX += 0.01f;
			Sprite->translateBounds(0.01f, 0.0f);
		}
		if (glfwGetKey(win->getWin(), GLFW_KEY_A) == GLFW_PRESS)
		{
			transX -= 0.01f;
			Sprite->translateBounds(-0.01f, 0.0f);
		}
		if (glfwGetKey(win->getWin(), GLFW_KEY_X) == GLFW_PRESS) transZ += 0.001f;
		if (glfwGetKey(win->getWin(), GLFW_KEY_Z) == GLFW_PRESS) transZ -= 0.001f;

		// rotate

		if (glfwGetKey(win->getWin(), GLFW_KEY_U) == GLFW_PRESS) rotateX += 0.001f;
		if (glfwGetKey(win->getWin(), GLFW_KEY_J) == GLFW_PRESS) rotateX -= 0.001f;
		if (glfwGetKey(win->getWin(), GLFW_KEY_I) == GLFW_PRESS) rotateY += 0.001f;
		if (glfwGetKey(win->getWin(), GLFW_KEY_K) == GLFW_PRESS) rotateY -= 0.001f;
		if (glfwGetKey(win->getWin(), GLFW_KEY_O) == GLFW_PRESS) rotateZ += 0.001f;
		if (glfwGetKey(win->getWin(), GLFW_KEY_L) == GLFW_PRESS) rotateZ -= 0.001f;

		// scale

		if (glfwGetKey(win->getWin(), GLFW_KEY_UP) == GLFW_PRESS) {
			scaleX += 0.001f;
			scaleY += 0.001f;
			scaleZ += 0.001f;
		}
		if (glfwGetKey(win->getWin(), GLFW_KEY_DOWN) == GLFW_PRESS) {
			scaleX -= 0.001f;
			scaleY -= 0.001f;
			scaleZ -= 0.001f;
		}
		//------
		render->clearBackground();

		//view
		render->setView(render->getShaderProgram(), render->getView());
		//Proj
		render->setProj(render->getShaderProgram(), render->getProj());

		//------
		//Sprite
		//Sprite load texture
		Sprite->loadTexture("res/assets/AprobamePorfa.jpg", GL_RGB);
		
		Sprite->SetPosition(transX, transY, transZ);
		Sprite->SetRotationX(rotateX);
		Sprite->SetRotationY(rotateY);
		Sprite->SetRotationZ(rotateZ);
		Sprite->SetScale(scaleX, scaleY, scaleZ);
		
		//------

		//Model
		render->setModel(render->getShaderProgram(), Sprite->getModel());



		render->drawTr();
		//------

		//Sprite2
		//Sprite load texture
		Sprite2->loadTexture("res/assets/dragon.png", GL_RGBA);

		//------
		render->setModel(render->getShaderProgram(), Sprite2->getModel());
		render->drawTr();

		//------
		//Collision detection
		std::cout << "min.x: " << Sprite->getBounds().min.x << std::endl;
		std::cout << "min.y: " << Sprite->getBounds().min.y << std::endl;
		if (Sprite->getBounds().min.x < Sprite2->getBounds().max.x
			&&
			Sprite->getBounds().max.x > Sprite2->getBounds().min.x
			&&
			Sprite->getBounds().min.y < Sprite2->getBounds().max.y
			&&
			Sprite->getBounds().max.y > Sprite2->getBounds().min.y
			)
			std::cout << "Colliding: YES" << std::endl;
		else
			std::cout << "Colliding: NO" << std::endl;

		win->swapBuffers();
		win->pollEvents();
	}

	glDeleteProgram(render->getShaderProgram());
	win->glfwTermine();
	return 0;
}