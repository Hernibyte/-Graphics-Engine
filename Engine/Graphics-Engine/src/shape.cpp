#include"shape.h"

float vertexBufferTri[] = {
	-0.5f,  0.5f, 0.0f,		1.0f, 0.0f, 0.0f,	1.0f, 1.0f,
	 0.5f,  0.5f, 0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,
	 0.5f, -0.5f, 0.0f,		0.0f, 0.0f, 1.0f,	0.0f, 0.0f,

	 0.5f, -0.5f, 0.0f,		0.0f, 0.0f, 1.0f,	0.0f, 0.0f,
	-0.5f, -0.5f, 0.0f,		1.0f, 1.0f, 1.0f,	1.0f, 0.0f,
	-0.5f,  0.5f, 0.0f,		1.0f, 0.0f, 0.0f,	1.0f, 1.0f
};
/*
float vertexBufferTri[] = {
	 0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,
	 0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,
	-0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,
	-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f
};

unsigned int quadIndices[] = {  // note that we start from 0!
	0, 1, 3,   // first triangle
	1, 2, 3    // second triangle
};

float vertexBufferTri[] = {
	-0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,
	 0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,
	 0.0f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.5f, 1.0f
};

unsigned int triIndices[] = {
	0, 1, 2
};
*/

Shape::Shape(renderer* _render, int _type) : Entity2D(_render) {
	render = _render;
	type = _type;
	tam = 48;
}

Shape::~Shape() {

}

void Shape::setBufferData() {
	render->setBufferData(tam, vertexBufferTri);
}