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

float vertexBufferQuadSprite[QUAD_VERTEX_BUFFER_SIZE] = {
	TL.x, TL.y, 0.0f,		1.0f, 0.0f, 0.0f,	0.0f, 0.5f,
	TR.x, TR.y, 0.0f,		0.0f, 1.0f, 0.0f,	0.5f, 0.5f,
	BR.x, BR.y, 0.0f,		0.0f, 0.0f, 1.0f,	0.5f, 0.0f,

	BR.x, BR.y, 0.0f,		0.0f, 0.0f, 1.0f,	0.5f, 0.0f,
	BL.x, BL.y, 0.0f,		1.0f, 1.0f, 1.0f,	0.0f, 0.0f,
	TL.x, TL.y, 0.0f,		1.0f, 0.0f, 0.0f,	0.0f, 0.5f
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
	tam = QUAD_VERTEX_BUFFER_SIZE;
	animation = NULL;

	for (int i = 0; i < QUAD_VERTEX_BUFFER_SIZE; i++)
	{
		vertexBuffer[i] = vertexBufferQuadSprite[i];
	}
}

sprite::~sprite() {
	//---
}

void sprite::loadTexture(const char* filePath, int type) {
	Texture.loadTexture(filePath, data, width, height, nrChannels, type);

	//std::cout << filePath << ": " << &vertexBuffer << std::endl;
	if (animation)
	{
		animation->Update();
		Frame frame = animation->GetAnimation()[animation->GetCurrentFrame()];

		vertexBuffer[6] = frame.frameCoords[0].u;
		vertexBuffer[7] = frame.frameCoords[0].v;
		vertexBuffer[14] = frame.frameCoords[1].u;
		vertexBuffer[15] = frame.frameCoords[1].v;
		vertexBuffer[22] = frame.frameCoords[2].u;
		vertexBuffer[23] = frame.frameCoords[2].v;
		vertexBuffer[30] = frame.frameCoords[2].u;
		vertexBuffer[31] = frame.frameCoords[2].v;
		vertexBuffer[38] = frame.frameCoords[3].u;
		vertexBuffer[39] = frame.frameCoords[3].v;
		vertexBuffer[46] = frame.frameCoords[0].u;
		vertexBuffer[47] = frame.frameCoords[0].v;

		setBufferData();
	}
}

void sprite::setBufferData() {
	render->setBufferData(tam, vertexBuffer);
}

void sprite::setAnimation(Animation* _animation)
{
	animation = _animation;
}

Animation* sprite::getAnimation()
{
	return animation;
}