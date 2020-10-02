#include"material.h"

glm::vec3* _colorRGB;

Material::Material() {
	_colorRGB = NULL;
	j = 0;
}

Material::~Material() {
	if (_colorRGB != NULL) {
		delete _colorRGB;
	}
}

void Material::setMaterial() {

}

void Material::setColor(float* arrayRGB, int tamArrayRGB, int repeticiones) {
	/*
	_colorRGB = new glm::vec3[repeticiones];
	for (int k = 0; k < repeticiones; k++) {
		for (int i = 0; i < tamArrayRGB; i++) {
			_colorRGB[k][i] = arrayRGB[j];
			j++;
		}
	}*/
}

glm::vec3* Material::getColorRGB() {
	return _colorRGB;
}