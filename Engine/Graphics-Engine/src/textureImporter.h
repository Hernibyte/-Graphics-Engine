#ifndef TEXTUREIMPORTER_H
#define TEXTUREIMPORTER_H
#include"includes.h"
#include "stb_image.h"

class textureImporter {
private:

public:
	void loadTexture(const char* filePath,
					 unsigned char* data, int width,
					 int height, int nrChannels);
};

#endif // !TEXTUREIPORTER_H