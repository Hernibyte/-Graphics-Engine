#ifndef SPRITE_H
#define SPRITE_H

#include "Animation.h"
#include "Entity2D.h"
#include "Includes.h"
#include "textureImporter.h"

#define RGB 0x1907
#define RGBA 0x1908

class GENGINE_API Sprite : public Entity2D{
private:
	unsigned char* data;
	int width;
	int height;
	int nrChannels;
	int tam;
	int type;
	textureImporter texture;
	Animation* animation;
public:
	Sprite(Renderer* _render);
	~Sprite();
	void loadTexture(const char* filePath, int type);
	void setBufferData();
	void setAnimation(Animation* _animation);
	Animation* getAnimation();
};

#endif // !SPRITE_H