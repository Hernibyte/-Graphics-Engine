#ifndef ENTITY_H
#define ENTITY_H

#include"includes.h"
#include"renderer.h"

struct GENGINE_API Transform {
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
};

struct GENGINE_API InternalData {
	glm::mat4 model;
	glm::mat4 translate;
	glm::mat4 rotateX;
	glm::mat4 rotateY;
	glm::mat4 rotateZ;
	glm::mat4 scale;
};

class GENGINE_API Entity {
protected:
	renderer* render;
	InternalData internalData;
	void UpdateMatrixModel();
public:
	Entity(renderer *_renderer);
	~Entity();
	Transform transform;
	renderer* GetRenderer();
	InternalData GetInternalData();
	void SetPosition(float x, float y, float z);
	void SetScale(float x, float y, float z);
	void SetRotationX(float x);
	void SetRotationY(float y);
	void SetRotationZ(float z);
	glm::mat4 getModel();
};

#endif // !ENTITY