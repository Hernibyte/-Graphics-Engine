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
	Tr->setBufferData();
	//Sprite->setBufferData();
	//shader
	render->setShader();
	//Set texture
	render->generateTexture();
	render->setParameterTexture();
	//Sprite load texture
	Sprite->loadTexture("res/assets/AprobamePorfa.jpg");
	//------
	glUseProgram(render->getShaderProgram());

	while (!win->detecWindowShouldClose()) {
		// Input

		if (glfwGetKey(win->getWin(), GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(win->getWin(), true);
		
		//transform

		if (glfwGetKey(win->getWin(), GLFW_KEY_W) == GLFW_PRESS) transY += 0.001f;
		if (glfwGetKey(win->getWin(), GLFW_KEY_S) == GLFW_PRESS) transY -= 0.001f;
		if (glfwGetKey(win->getWin(), GLFW_KEY_D) == GLFW_PRESS) transX += 0.001f;
		if (glfwGetKey(win->getWin(), GLFW_KEY_A) == GLFW_PRESS) transX -= 0.001f;
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
		//------
		
		Tr->SetPosition(transX, transY, transZ);
		Tr->SetRotationX(rotateX);
		Tr->SetRotationY(rotateY);
		Tr->SetRotationZ(rotateZ);
		Tr->SetScale(scaleX, scaleY, scaleZ);
		
		//------

		glUseProgram(render->getShaderProgram());

		//Model
		render->setModel(render->getShaderProgram(), Tr->getModel());
		//view
		render->setView(render->getShaderProgram(), render->getView());
		//Proj
		render->setProj(render->getShaderProgram(), render->getProj());
		//------
		render->drawTr();

		win->swapBuffers();
		win->pollEvents();
	}

	glDeleteProgram(render->getShaderProgram());
	win->glfwTermine();
	return 0;
}