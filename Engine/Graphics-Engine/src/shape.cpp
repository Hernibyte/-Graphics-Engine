#include"shape.h"

float vertexBufferTri[] = {
	-0.5f , -0.5f , 0.0f, 1.0f , 0.0f ,0.0f,
	 0.5f , -0.5f , 0.0f, 0.0f , 1.0f ,0.0f, 
	 0.0f ,  0.5f , 0.0f, 0.0f , 0.0f, 1.0f
};

float ColorTri[] {
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f
};

int tam = 18;

Shape::Shape(renderer* _render) : Entity2D(_render) {
	render = _render;
	_posAttrib = 0;
	_colorAttrib = 1;
}

Shape::Shape(renderer* _render, Material* _material) : Entity2D(_render, _material) {
	render = _render;
	material = _material;
}

void Shape::setVBO(unsigned int _VBO) {
	render->bindVBO(_VBO);
}

void Shape::setBufferData() {
	glBufferData(GL_ARRAY_BUFFER, tam * sizeof(float), vertexBufferTri, GL_STATIC_DRAW);
}

void Shape::bindColor() {
	//material->setColor(ColorTri, 3, 3);
}

void Shape::setVertexsAttrib(unsigned int& shaderProgram) {
	_posAttrib = glGetAttribLocation(shaderProgram, "aPos");
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0);
	glEnableVertexAttribArray(0);
	_colorAttrib = glGetAttribLocation(shaderProgram, "aColor");
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

void Shape::drawTr() {
	glDrawArrays(GL_TRIANGLES, 0, 6);
}