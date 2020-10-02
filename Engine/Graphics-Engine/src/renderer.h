#ifndef RENDERER_H
#define RENDERER_H

#include"includes.h"
//#include"window.h"

#define TRPOS6 6
#define TRPOS3 3

class GENGINE_API renderer {
private:
	unsigned int VBO;
	unsigned int VAO;
	unsigned int shaderProgram;
public:
	unsigned int& getShaderProgram();
	void createVBO();
	void createVAO();
	void bindVBO(unsigned int _VBO);
	void bindVAO(unsigned int _VAO);
	unsigned int getVBO();
	unsigned int getVAO();
	void clearBackground();
	void setShader();
	unsigned int compileShader(unsigned int type, const char* source);
	int createShaderProgram(const char * vertexPath, const char * fragmentPath);
	void setModel(unsigned int& _shaderProg, glm::mat4 model);
};

#endif // !RENDERER_H