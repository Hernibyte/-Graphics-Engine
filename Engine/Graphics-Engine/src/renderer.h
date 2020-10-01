#ifndef RENDERER_H
#define RENDERER_H

#include"includes.h"
//#include"window.h"

#define TRPOS6 6
#define TRPOS3 3

class GENGINE_API renderer {
private:
	unsigned int shaderProgram;
public:
	unsigned int& getShaderProgram();
	void bindVertexBuffer(unsigned int VBO);
	void clearBackground();
	void setShader();
	unsigned int compileShader(unsigned int type, const char* source);
	int createShaderProgram(const char * vertexPath, const char * fragmentPath);
};

#endif // !RENDERER_H