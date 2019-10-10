#pragma once
#include <iostream>
#include <typeinfo>

#include "Animation.h"
#include "Game.h"

/// <summary>
/// @Author : Oisin Wilson
/// </summary>


class State
{
public:
	virtual void handleInput() {}
	virtual void update() {}

	virtual void idle(Animation* a){}
	virtual void jumping(Animation* a){}
	virtual void walking(Animation* a){}
	
	int m_startValue;
	int m_maxValue;
};
