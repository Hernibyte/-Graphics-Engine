#ifndef WINDOW_H
#define WINDOW_h

#include"includes.h"

class GENGINE_API Window {
private:
	int width;
	int height;
public:
	Window();
	GLFWwindow* getWin();
	void setWidth(int _width);
	void setHeight(int _height);
	int getWigth();
	int getHeight();
	int createWindowValidate();
	void createContexCurrent();
	void initGLEW();
	bool detecWindowShouldClose();
	void swapBuffers();
	void pollEvents();
	void glfwTermine();
};

#endif // !WINDOW_H