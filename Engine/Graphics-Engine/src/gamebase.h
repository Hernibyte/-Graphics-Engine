#ifndef GAMEBASE_H
#define GAMEBASE_H

#include"includes.h"
#include"window.h"
#include"renderer.h"
#include"shape.h"

class GENGINE_API gamebase {
private:
	float transX;
	float transY;
	float transZ;
	float rotateX;
	float rotateY;
	float rotateZ;
	float scaleX;
	float scaleY;
	float scaleZ;
	window* win;
	renderer* render;
	Shape* Tr;
public:
	gamebase();
	~gamebase();
	int startEngine();
};

#endif // !GAMEBASE_H