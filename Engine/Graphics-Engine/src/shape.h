#ifndef SHAPE_H
#define SHAPE_H

#include"includes.h"
#include"Entity2D.h"

class GENGINE_API Shape : public Entity2D{
private:

public:
	Shape(renderer* _render);
	~Shape();
	void setBufferData();
};

#endif // !SHAPE_H