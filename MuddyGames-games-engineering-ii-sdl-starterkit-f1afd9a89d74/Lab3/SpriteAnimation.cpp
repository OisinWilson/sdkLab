#include "SpriteAnimation.h"

/// <summary>
/// @Author : Oisin Wilson
/// </summary>

SpriteAnimation::SpriteAnimation()
{
	m_currentFrame = 0;
	m_maxFrames = 0;
	m_frameInc = 1;

	m_frameRate = 100; //Milliseconds
	m_oldTime = 0;

	m_oscillate = false;
}


SpriteAnimation::~SpriteAnimation()
{
}


void SpriteAnimation::OnAnimate() {
	if (m_oldTime + m_frameRate > SDL_GetTicks()) {
		return;
	}

	m_oldTime = SDL_GetTicks();

	m_currentFrame += m_frameInc;

	if (m_oscillate) {
		if (m_frameInc > 0) {
			if (m_currentFrame >= m_maxFrames) {
				m_frameInc = -m_frameInc;
			}
		}
		else {
			if (m_currentFrame <= 0) {
				m_frameInc = -m_frameInc;
			}
		}
	}
	else {
		if (m_currentFrame >= m_maxFrames) {
			m_currentFrame = 0;
		}
	}
}

void SpriteAnimation::SetFrameRate(int Rate) {
	m_frameRate = Rate;
}

void SpriteAnimation::SetCurrentFrame(int Frame) {
	if (Frame < 0 || Frame >= m_maxFrames) return;

	m_currentFrame = Frame;
}

int SpriteAnimation::GetCurrentFrame() {
	return m_currentFrame;
}