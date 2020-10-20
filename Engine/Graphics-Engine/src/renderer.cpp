#include"renderer.h"

renderer::renderer() {
	unsigned int _posAttrib = 0;
	unsigned int _colorAttrib = 1;
}

unsigned int& renderer::getShaderProgram() {
	return shaderProgram;
}

void renderer::createVBO() {
	glGenBuffers(1, &VBO);
}

void renderer::createVAO() {
	glGenVertexArrays(1, &VAO);
}

void renderer::bindVBO(unsigned int _VBO) {
	VBO = _VBO;
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
}

void renderer::bindVAO(unsigned int _VAO) {
	VAO = _VAO;
	glBindVertexArray(VAO);
}

unsigned int renderer::getVBO() {
	return VBO;
}

unsigned int renderer::getVAO() {
	return VAO;
}

void renderer::clearBackground() {
	glClearColor(0.5f, 0.2f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void renderer::setShader() {
	shaderProgram = createShaderProgram("../Graphics-Engine/res/shaders/shader-vs.shader","../Graphics-Engine/res/shaders/shader-fs.shader");
}

unsigned int renderer::compileShader(unsigned int type, const char* source) {
	unsigned int id = glCreateShader(type);

	std::string sourceShaderCode;

	std::ifstream sourceShaderFile;

	sourceShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try {
		sourceShaderFile.open(source);
		std::stringstream sourceShaderStream;

		sourceShaderStream << sourceShaderFile.rdbuf();

		sourceShaderFile.close();

		sourceShaderCode = sourceShaderStream.str();
	}
	catch (std::ifstream::failure& e) {
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}

	const char* srcCode = sourceShaderCode.c_str();

	glShaderSource(id, 1, &srcCode, nullptr);
	glCompileShader(id);

	return id;
}

int renderer::createShaderProgram(const char* vertexPath, const char* fragmentPath) {
	unsigned int sProgram = glCreateProgram();
	unsigned int vertex = compileShader(GL_VERTEX_SHADER, vertexPath);
	unsigned int fragment = compileShader(GL_FRAGMENT_SHADER, fragmentPath);

	glAttachShader(sProgram, vertex);
	glAttachShader(sProgram, fragment);
	glLinkProgram(sProgram);
	glValidateProgram(sProgram);

	glDeleteShader(vertex);
	glDeleteShader(fragment);

	return sProgram;
}

void renderer::setModel(unsigned int& _shaderProg, glm::mat4 model) {
	unsigned int modelLoc = glGetUniformLocation(_shaderProg, "model");

	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
}

void renderer::setProj(unsigned int& _shaderProg, glm::mat4 projection) {
	unsigned int projectionLoc = glGetUniformLocation(_shaderProg, "projection");

	updateProj(projection);

	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
}

void renderer::updateProj(glm::mat4 projection) {
	projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
}

void renderer::setView(unsigned int& _shaderProg, glm::mat4 view) {
	unsigned int viewLoc = glGetUniformLocation(_shaderProg, "view");

	updateView(view);

	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
}

void renderer::updateView(glm::mat4 view) {
	view = glm::lookAt(getCameraPos(), getCameraPos() + getCameraFront(), getCameraUp());
}

glm::mat4 renderer::getView() {
	return _VP.view;
}

glm::mat4 renderer::getProj() {
	return _VP.projection;
}

glm::vec3 renderer::getCameraPos() {
	return _VP.cameraPos;
}

glm::vec3 renderer::getCameraFront() {
	return _VP.cameraFront;
}

glm::vec3 renderer::getCameraUp() {
	return _VP.cameraUp;
}

void renderer::setVertexAttrib() {
	_posAttrib = glGetAttribLocation(shaderProgram, "aPos");
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0);
	glEnableVertexAttribArray(0);
	_colorAttrib = glGetAttribLocation(shaderProgram, "aColor");
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

void renderer::drawTr(){
	glDrawArrays(GL_TRIANGLES, 0, 6);
}