#pragma once

/// <summary>
/// @Author : Oisin Wilson
/// </summary>

#include "State.h"


class Idle : public State
{
public:
	Idle();
	~Idle() {};
	void handleInput();
	void update();
	void jumping(Animation* a);
	void walking(Animation* a);
};

