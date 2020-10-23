#ifndef RENDERER_H
#define RENDERER_H

#include"includes.h"

struct matrixVP {
	glm::mat4 view;
	glm::mat4 projection;
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
};

#define TRPOS6 6
#define TRPOS3 3

class GENGINE_API renderer {
private:
	unsigned int VBO;
	unsigned int VAO;
	unsigned int shaderProgram;
	unsigned int _posAttrib;
	unsigned int _colorAttrib;
	matrixVP _VP;
public:
	renderer();
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
	void setProj(unsigned int& _shaderProg, glm::mat4 projection);
	void updateProj(glm::mat4 projection);
	void setView(unsigned int& _shaderProg, glm::mat4 view);
	void updateView(glm::mat4 view);
	glm::mat4 getView();
	glm::mat4 getProj();
	glm::vec3 getCameraPos();
	glm::vec3 getCameraFront();
	glm::vec3 getCameraUp();
	void setVertexAttrib();
	void updateUnifornTexture();
	void drawTr();
};

#endif // !RENDERER_H