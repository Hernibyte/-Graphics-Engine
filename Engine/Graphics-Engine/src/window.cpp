#include"window.h"

GLFWwindow* win;

window::window() {
	setWidth(1280);
	setHeight(720);
	win = glfwCreateWindow(width, height, "Unreal Engine 6", NULL, NULL);
}

GLFWwindow* window::getWin() {
	return win;
}

void window::setWidth(int _width) {
	width = _width;
}

void window::setHeight(int _height) {
	height = _height;
}

int window::getWigth() {
	return width;
}

int window::getHeight() {
	return height;
}

int window::createWindowValidate() {
	if (!win) {
		glfwTerminate();
		return -1;
	}
}

void window::createContexCurrent() {
	glfwMakeContextCurrent(win);
}

void window::initGLEW() {
	glewInit();
}

bool window::detecWindowShouldClose() {
	return glfwWindowShouldClose(win);
}

void window::swapBuffers() {
	glfwSwapBuffers(win);
}

void window::pollEvents() {
	glfwPollEvents();
}

void window::glfwTermine() {
	glfwTerminate();
}