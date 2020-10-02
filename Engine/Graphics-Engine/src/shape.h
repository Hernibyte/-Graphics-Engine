#ifndef SHAPE_H
#define SHAPE_H

#include"includes.h"
#include"Entity2D.h"

class GENGINE_API Shape : public Entity2D{
private:
	unsigned int _posAttrib;
	unsigned int _colorAttrib;
public:
	Shape(renderer* _render);
	Shape(renderer* _render, Material* _material);
	void setVBO(unsigned int _VBO);
	void setBufferData();
	void bindColor();
	void setVertexsAttrib(unsigned int& shaderProgram);
	void drawTr();
};

#endif // !SHAPE_H