#ifndef TIME_H
#define TIME_H
#include <chrono>
#include <time.h>
#include "includes.h"

class GENGINE_API Time {
private:
	std::chrono::system_clock::time_point startTime;
	float deltaTime;
	float timeScale;
	float elapsedTime = 0;
	float framesCounter;
	int frames;
	float fps = 0;
public:
	Time();
	~Time();
	void Reset();
	void SetTimeScale(float t);
	float GetTimeScale();
	float GetSeconds();
	void StartTime();
	void Tick();
	float DeltaTime();
	void CalculateFps();
	float GetFps();
	void FPS();
};

#endif // !TIME_H