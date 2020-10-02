#ifndef MATERIAL_H
#define MATERIAL_H

#include"includes.h"

class GENGINE_API Material {
private:
	int j;
public:
	Material();
	~Material();
	void setMaterial();
	void setColor(float* arrayRGB, int tamArrayRGB, int repeticiones);
	glm::vec3* getColorRGB();
};

#endif // !MATERIAL_H