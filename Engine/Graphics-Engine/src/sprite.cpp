#include"sprite.h"

sprite::sprite(renderer* _render) : Entity2D(_render) {
	render = _render;
}

sprite::~sprite() {
	glDeleteTextures(1, &texture);
}

void sprite::genTexture(){
	stbi_set_flip_vertically_on_load(1);
	glGenTextures(1, &texture);
	glActiveTexture(GL_TEXTURE0);
}

void sprite::bindTexture(){
	glBindTexture(GL_TEXTURE_2D, texture);
}

void sprite::setParametrer(){
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_CLAMP_TO_EDGE);
}

void sprite::setTexture(const char* filePath){
	Texture.loadTexture(filePath, data, width, height, nrChannels);
}