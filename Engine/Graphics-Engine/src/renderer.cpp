#include"renderer.h"

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

void renderer::setModel(unsigned int& _shaderProg, glm::mat4 model, glm::mat4 projection, glm::mat4 view) {
	unsigned int modelLoc = glGetUniformLocation(_shaderProg, "model");

	glUseProgram(getShaderProgram());

	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
}

glm::mat4 renderer::getView(){
	return _MVP.view;
}

glm::mat4 renderer::getProj(){
	return _MVP.projection;
}

