#include"Entity2D.h"

Entity2D::Entity2D(Renderer* _render) : Entity(_render) {
	render = _render;
	bounds.min = bounds.max = vec2(0.0f, 0.0f);
}

Entity2D::Entity2D(Renderer* _render, vec2 _boundsMin, vec2 _boundsMax) : Entity(_render) {
	render = _render;

	bounds.min = _boundsMin;
	bounds.max = _boundsMax;
	bounds.size = vec2(bounds.max.x - bounds.min.x, bounds.max.y - bounds.min.y);
}

void Entity2D::setBounds(Bounds _bounds)
{
	bounds = _bounds;
}

void Entity2D::translateBounds(float transX, float transY)
{
	bounds.min.x += transX;
	bounds.max.x += transX;

	bounds.min.y += transY;
	bounds.max.y += transY;
}

Bounds Entity2D::getBounds()
{
	return bounds;
}