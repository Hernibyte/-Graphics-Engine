#ifndef GAMEBASE_H
#define GAMEBASE_H

#include"includes.h"
#include"window.h"
#include"renderer.h"

class GENGINE_API gamebase {
private:
	window* win;
	renderer* render;
public:
	gamebase();
	int startEngine();
};

#endif // !GAMEBASE_H