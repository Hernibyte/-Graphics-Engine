#include"Animation.h"

Animation::Animation() {
	currentTime = 0;
	currentFrame = 0;
	length = 200;
}
Animation::~Animation() {
	if (animations.size() > 0)
		animations.clear();
	if (totalFrames.size() > 0)
		totalFrames.clear();
}
void Animation::Update(Time& time) {
	currentTime += (time.DeltaTime());

	while (currentTime >= length) {
		currentTime -= length;
	}

	float frameLength = length / animations[currentAnimation].size();
	currentFrame = static_cast<int>(currentTime / frameLength);
}
void Animation::AddFrame(float frameX, float frameY,
	int spriteWidth, int spriteHeigth,
	int textureWidth, int textureHeigth,
	float timeToAnim, int _totalFrames, int countFramesForFilas) {
	//---
	length = timeToAnim;

	std::cout << "total frames" << _totalFrames << std::endl;
	_totalFrames = _totalFrames + countFramesForFilas;
	float index_X = 0;
	float index_Y = 0;
	Frame frame;
	std::cout << "total frames" << _totalFrames << std::endl;
	for (int i = 0; i < _totalFrames; i++) {
		//--------
		frame.frameCoords[0].u = ((frameX + index_X) / textureWidth);
		frame.frameCoords[0].v = ((spriteHeigth + index_Y) / textureHeigth);
		//--------
		frame.frameCoords[1].u = (((frameX + index_X) + spriteWidth) / textureWidth);
		frame.frameCoords[1].v = ((spriteHeigth + index_Y) / textureHeigth);
		//--------
		frame.frameCoords[2].u = (((frameX + index_X) + spriteWidth) / textureWidth);
		frame.frameCoords[2].v = ((frameY + index_Y) / textureHeigth);

		//--------
		frame.frameCoords[3].u = ((frameX + index_X) / textureWidth);
		frame.frameCoords[3].v = ((frameY + index_Y) / textureHeigth);
		//--------
		totalFrames.push_back(frame);
		index_X += spriteWidth;
		if (i > 0)
		{
			if (i % countFramesForFilas == 0)
			{
				index_Y += spriteHeigth;
				animations.push_back(totalFrames);
				totalFrames.clear();
			}
		}
	}
	animations[0].resize(countFramesForFilas);
}
int Animation::GetCurrentFrame() {
	return currentFrame;
}
std::vector<Frame>& Animation::GetAnimation() {
	if (currentAnimation < animations.size())
		return animations[currentAnimation];

	return animations[animations.size() - 1];
}
void Animation::SetCurrentAnimation(int _currentAnimation) {
	currentAnimation = _currentAnimation;
}
void Animation::AddFrame(float frameX, float frameY,
	int spriteWidth, int spriteHeigth,
	int textureWidth, int textureHeigth, float timeToAnim) {
	//---
	length = timeToAnim;

	Frame frame;

	frame.frameCoords[0].u = ((frameX) / textureWidth);
	frame.frameCoords[0].v = ((spriteHeigth + frameY) / textureHeigth);
	//--------
	frame.frameCoords[1].u = (((frameX)+spriteWidth) / textureWidth);
	frame.frameCoords[1].v = ((spriteHeigth + frameY) / textureHeigth);
	//--------
	frame.frameCoords[2].u = (((frameX)+spriteWidth) / textureWidth);
	frame.frameCoords[2].v = ((frameY) / textureHeigth);
	//--------
	frame.frameCoords[3].u = ((frameX) / textureWidth);
	frame.frameCoords[3].v = ((frameY) / textureHeigth);
	//--------
	totalFrames.push_back(frame);
}
void Animation::AddAnimation() {
	if (totalFrames.size() > 0)
	{
		animations.push_back(totalFrames);
		totalFrames.clear();
	}
}