#include"gamebase.h"

gamebase::gamebase() {
	glfwInit();
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
	Tr->setMaterial();

	glUseProgram(render->getShaderProgram());

	while (!win->detecWindowShouldClose()) {

		render->clearBackground();
		
		Tr->SetPosition(0.2f, 0.2f, 0.0f);
		render->setModel(render->getShaderProgram(), Tr->getModel(), render->getProj(), render->getView());
		Tr->drawTr();

		win->swapBuffers();
		win->pollEvents();
	}

	glDeleteProgram(render->getShaderProgram());
	win->glfwTermine();
	return 0;
}
