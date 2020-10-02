#include"entity.h"

Entity::Entity(renderer *_renderer) {
	render = _renderer;

	internalData.model = glm::mat4(1.0f);
	internalData.rotateX = glm::mat4(1.0f);
	internalData.rotateY = glm::mat4(1.0f);
	internalData.rotateZ = glm::mat4(1.0f);
	internalData.scale = glm::mat4(1.0f);
	internalData.translate = glm::mat4(1.0f);

	SetPosition(0, 0, 0);
	SetRotationX(0);
	SetRotationY(0);
	SetRotationZ(0);
	SetScale(1, 1, 1);
}

Entity::~Entity() {

}

renderer* Entity::GetRenderer() {
	return render;
}

InternalData Entity::GetInternalData() {
	return internalData;
}

void Entity::SetPosition(float x, float y, float z) {
	transform.position[0] = x;
	transform.position[1] = y;
	transform.position[2] = z;

	internalData.translate = glm::translate(glm::mat4(1.0f), transform.position);
	UpdateMatrixModel();
}

void Entity::SetScale(float x, float y, float z) {
	transform.scale[0] = x;
	transform.scale[1] = y;
	transform.scale[2] = z;

	internalData.scale = glm::scale(glm::mat4(1.0f), transform.scale);
	UpdateMatrixModel();
}

void Entity::SetRotationX(float x) {
	transform.rotation[0] = x;
	glm::vec3 axis;
	axis[0] = 1.0f;
	axis[1] = 0.0f;
	axis[2] = 0.0f;

	internalData.rotateX = glm::rotate(glm::mat4(1.0f), x, axis);
	UpdateMatrixModel();
}

void Entity::SetRotationY(float y) {
	transform.rotation[1] = y;
	glm::vec3 axis;
	axis[0] = 0.0f;
	axis[1] = 1.0f;
	axis[2] = 0.0f;

	internalData.rotateY = glm::rotate(glm::mat4(1.0f), y, axis);
	UpdateMatrixModel();
}

void Entity::SetRotationZ(float z) {
	transform.rotation[2] = z;
	glm::vec3 axis;
	axis[0] = 0.0f;
	axis[1] = 0.0f;
	axis[2] = 1.0f;

	internalData.rotateY = glm::rotate(glm::mat4(1.0f), z, axis);
	UpdateMatrixModel();
}

glm::mat4 Entity::getModel() {
	return internalData.model;
}

//---------------------

void Entity::UpdateMatrixModel() {
	internalData.model = internalData.translate * 
	internalData.rotateX * internalData.rotateY * 
	internalData.rotateZ * internalData.scale;
}