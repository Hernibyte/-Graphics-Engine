#include"Entity2D.h"

Entity2D::Entity2D(renderer* _render) : Entity(_render) {
	render = _render;
}

Entity2D::Entity2D(renderer* _render, Material* _material) : Entity(_render) {
	render = _render;
	material = _material;
}

Entity2D::~Entity2D() {

}