#ifndef SHAPE_H
#define SHAPE_H

#include"includes.h"
#include"Entity2D.h"

class GENGINE_API Shape : public Entity2D{
private:
	unsigned int _posAttrib;
	unsigned int _colorAttrib;
	Entity* transform;
public:
	Shape(renderer* _render);
	~Shape();
	void setVBO(unsigned int _VBO);
	void setBufferData();
	void setVertexsAttrib(unsigned int& shaderProgram);
	void drawTr();
	void setMaterial();
	void SetVertexMaterial(glm::vec3* materials, float* VBA, int start, int offset, int repeticiones, int countElementsForRepe);
};

#endif // !SHAPE_H