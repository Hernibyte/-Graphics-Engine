#include"shape.h"

float vertexBufferTri[] = {
	-0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,
	 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
	 0.0f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f
};

float ColorTri[] {
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f
};

//glm::vec3 changeColor = { 1.0f, 1.0f, 1.0f };

int tam = 24;

Shape::Shape(renderer* _render) : Entity2D(_render) {
	render = _render;
}

Shape::~Shape() {

}

void Shape::setBufferData() {
	glBufferData(GL_ARRAY_BUFFER, tam * sizeof(float), vertexBufferTri, GL_DYNAMIC_DRAW);
}