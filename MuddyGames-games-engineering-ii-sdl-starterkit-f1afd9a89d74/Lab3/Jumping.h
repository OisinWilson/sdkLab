#pragma once

/// <summary>
/// @Author : Oisin Wilson
/// </summary>

#include "State.h"

class Jumping : public State
{
public:
	Jumping();
	~Jumping();
	void idle(Animation* a);
	void walking(Animation* a);
};

