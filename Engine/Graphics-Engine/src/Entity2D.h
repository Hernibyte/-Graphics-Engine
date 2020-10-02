#ifndef ENTITY2D_H
#define ENTITY2D_H

#include"includes.h"
#include"entity.h"
#include"material.h"

class GENGINE_API Entity2D : public Entity {
public:
	Entity2D(renderer* _render);
	Entity2D(renderer* _render, Material* _material);
	~Entity2D();
	Material* material;
};

#endif // !ENTITY2D_H