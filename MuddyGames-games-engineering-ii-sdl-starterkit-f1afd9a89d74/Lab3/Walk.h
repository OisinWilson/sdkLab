#pragma once

/// <summary>
/// @Author : Oisin Wilson
/// </summary>

#include "State.h"

class Walk : public State
{
public:
	Walk();
	~Walk();
	void idle(Animation* a);
	void jumping(Animation* a);
};

