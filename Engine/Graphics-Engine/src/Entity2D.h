#ifndef ENTITY2D_H
#define ENTITY2D_H

#include"includes.h"
#include"entity.h"

class GENGINE_API Entity2D : public Entity {
public:
	Entity2D(renderer* _render);
};

#endif // !ENTITY2D_H