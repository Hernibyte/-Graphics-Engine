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

glm::vec3 changeColor = { 1.0f, 1.0f, 1.0f };

int tam = 18;

Shape::Shape(renderer* _render) : Entity2D(_render) {
	render = _render;
	transform = new Entity(_render);
}

Shape::~Shape() {
	if (transform != NULL) delete transform;
}

void Shape::setVBO(unsigned int _VBO) {
	render->bindVBO(_VBO);
}

void Shape::setBufferData() {
	glBufferData(GL_ARRAY_BUFFER, tam * sizeof(float), vertexBufferTri, GL_STATIC_DRAW);
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

void Shape::setMaterial() {
	//material->setColor(ColorTri, 4, 3);
	//SetVertexMaterial(material->getColorRGB(), vertexBufferTri, 3, 4, 3, 4);
}

void Shape::SetVertexMaterial(glm::vec3* materials, float* VBA, int start, int offset, int repeticiones, int countElementsForRepe) {
	
}