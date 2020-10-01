#include"gamebase.h"

gamebase::gamebase() {
	glfwInit();
	win = new window();
	render = new renderer();
}

int gamebase::startEngine() {
	if (!glfwInit() || win == NULL) return -1;

	win->createWindowValidate();
	win->createContexCurrent();
	win->initGLEW();

	//shader
	render->setShader();
	//------

	glUseProgram(render->getShaderProgram());

	while (!win->detecWindowShouldClose()) {

		render->clearBackground();

		glUseProgram(render->getShaderProgram());


		win->swapBuffers();
		win->pollEvents();
	}

	glDeleteProgram(render->getShaderProgram());
	win->glfwTermine();
	return 0;
}
