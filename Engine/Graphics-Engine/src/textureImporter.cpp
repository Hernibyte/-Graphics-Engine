#include"textureImporter.h"

void textureImporter::loadTexture(const char* filePath, unsigned char* data, int width, int height, int nrChannels, int type){
	data = stbi_load(filePath, &width, &height, &nrChannels, 0);
	
	if (data) {
		switch (type) {
		case GL_RGB:
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
			break;
		case GL_RGBA:
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
			break;
		}
	}
	else
		std::cout << "Failed to load texture" << std::endl;
		
	stbi_image_free(data);
}