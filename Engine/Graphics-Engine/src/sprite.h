#ifndef SPRITE_H
#define SPRITE_H

#include"includes.h"
#include"Entity2D.h"
#include "textureImporter.h"
#include "Animation.h"

class GENGINE_API Sprite : public Entity2D{
private:
	unsigned char* data;
	int width;
	int height;
	int nrChannels;
	textureImporter Texture;
	int tam;
	int type;
	Animation* animation;
public:
	Sprite(Renderer* _render, int _type);
	~Sprite();
	void loadTexture(const char* filePath, int type);
	void setBufferData();
	void setAnimation(Animation* _animation);
	Animation* getAnimation();
};

#endif // !SPRITE_H