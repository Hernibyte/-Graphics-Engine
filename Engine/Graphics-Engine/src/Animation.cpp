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

}
void Animation::AddFrame(float frameX, float frameY,
	int spriteWidth, int spriteHeigth,
	int textureWidth, int tectureHeight,
	float timeToAnim, int totalFrames, int countFilas) {

}
int Animation::GetCurrentFrame() {

}
std::vector<Frame>& Animation::GetAnimation() {

}
void Animation::SetCurrentAnimation(int _currentAnimation) {
	currentAnimation = _currentAnimation;
}
void Animation::AddFrame(float frameX, float frameY,
	int spriteWidth, int spriteHeigth,
	int textureWigth, int textureHeigth, float timeToAnim) {

}
void Animation::AddAnimation() {

}