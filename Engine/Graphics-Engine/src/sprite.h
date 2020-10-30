#ifndef SPRITE_H
#define SPRITE_H

#include"includes.h"
#include"Entity2D.h"
#include "textureImporter.h"

class GENGINE_API sprite : public Entity2D{
private:
	unsigned char* data;
	int width;
	int height;
	int nrChannels;
	textureImporter Texture;
	int tam;
	int type;
public:
	sprite(renderer* _render, int _type);
	~sprite();
	void loadTexture(const char* filePath);
	void setBufferData();
};

#endif // !SPRITE_H