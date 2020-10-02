#include"material.h"

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

}

glm::vec3* Material::getColorRGB() {
	return _colorRGB;
}