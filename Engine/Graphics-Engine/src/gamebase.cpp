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
	Tr = new Shape(render);
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
}

int gamebase::startEngine() {
	if (!glfwInit() || win == NULL) return -1;

	win->createWindowValidate();
	win->createContexCurrent();
	win->initGLEW();

	//create VBO
	render->createVBO();
	//create Tr
	Tr->setVBO(render->getVBO());
	Tr->setBufferData();
	Tr->setVertexsAttrib(render->getShaderProgram());
	//shader
	render->setShader();
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
		
		Tr->SetPosition(transX, transY, transZ);
		Tr->SetRotationX(rotateX);
		Tr->SetRotationY(rotateY);
		Tr->SetRotationZ(rotateZ);
		Tr->SetScale(scaleX, scaleY, scaleZ);

		glUseProgram(render->getShaderProgram());

		render->setModel(render->getShaderProgram(), Tr->getModel());
		Tr->drawTr();

		win->swapBuffers();
		win->pollEvents();
	}

	glDeleteProgram(render->getShaderProgram());
	win->glfwTermine();
	return 0;
}
