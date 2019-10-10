#pragma once

/// <summary>
/// @Author : Oisin Wilson
/// </summary>

#include <SDL.h>

class SpriteAnimation
{
public:
	SpriteAnimation();
	~SpriteAnimation();
	
	void OnAnimate();
	void SetFrameRate(int Rate);
	void SetCurrentFrame(int Frame);
	int GetCurrentFrame();

	int m_maxFrames;
	bool m_oscillate;

private:
	int m_currentFrame;
	int m_frameInc;
	int m_frameRate; //Milliseconds
	long m_oldTime;
};

