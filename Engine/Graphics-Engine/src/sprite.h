#ifndef SPRITE_H
#define SPRITE_H

#include"includes.h"
#include"Entity2D.h"
#include"textureImporter.h"

class GENGINE_API sprite : public Entity2D{
private:
	unsigned int texture;
	unsigned char* data;
	int width;
	int height;
	int nrChannels;
	textureImporter Texture;
public:
	sprite(renderer* _render);
	~sprite();
	void genTexture();
	void bindTexture();
	void setParametrer();
	void setTexture(const char* filePath);
};

#endif // !SPRITE_H