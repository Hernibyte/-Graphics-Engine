#ifndef ENTITY2D_H
#define ENTITY2D_H

#include"includes.h"
#include"entity.h"
using namespace glm;

struct Bounds
{
	vec2 min;
	vec2 max;
	vec2 size;
};

class GENGINE_API Entity2D : public Entity {
	Bounds bounds;
public:
	Entity2D(renderer* _render);
	Entity2D(renderer* _render, vec2 _boundsMin, vec2 _boundsMax);
	void setBounds(Bounds _bounds);
	Bounds getBounds();
	void translateBounds(float transX, float transY);
};

#endif // !ENTITY2D_H