#include"sprite.h"
using namespace glm;

float vertexBufferTriSprite[] = {
	-0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,
	 0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,
	 0.0f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.5f, 1.0f
}; 

unsigned int triIndicesSprite[] = {
	0, 1, 2
};

//T = top
//B = bottom
//L = left
//R = right
vec2 TL = vec2(-0.5f,  0.5f);
vec2 TR = vec2( 0.5f,  0.5f);
vec2 BL = vec2(-0.5f, -0.5f);
vec2 BR = vec2( 0.5f, -0.5f);
vec2 _boundsMin = BL;
vec2 _boundsMax = TR;

float vertexBufferQuadSprite[] = {
	/*-0.5f,  0.5f*/TL.x, TL.y, 0.0f,		1.0f, 0.0f, 0.0f,	1.0f, 1.0f,
	/* 0.5f,  0.5f*/TR.x, TR.y, 0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,
	/* 0.5f, -0.5f*/BR.x, BR.y, 0.0f,		0.0f, 0.0f, 1.0f,	0.0f, 0.0f,
	/*			  */
	/* 0.5f, -0.5f*/BR.x, BR.y, 0.0f,		0.0f, 0.0f, 1.0f,	0.0f, 0.0f,
	/*-0.5f, -0.5f*/BL.x, BL.y, 0.0f,		1.0f, 1.0f, 1.0f,	1.0f, 0.0f,
	/*-0.5f,  0.5f*/TL.x, TL.y, 0.0f,		1.0f, 0.0f, 0.0f,	1.0f, 1.0f 
};
/*
float vertexBufferQuad[] = {
	 0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,
	 0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,
	-0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,
	-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f
};*/

unsigned int quadIndicesSprite[] = {  // note that we start from 0!
	0, 1, 3,   // first triangle
	1, 2, 3    // second triangle
};

sprite::sprite(renderer* _render, int _type) : Entity2D(_render, _boundsMin, _boundsMax) {
	render = _render;
	type = _type;
	tam = 48;
}

sprite::~sprite() {
	//---
}

void sprite::loadTexture(const char* filePath, int type){
	Texture.loadTexture(filePath, data, width, height, nrChannels, type);
}

void sprite::setBufferData() {
	render->setBufferData(tam, vertexBufferQuadSprite);
}