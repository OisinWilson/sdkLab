#include "Jumping.h"
#include "Idle.h"
#include "Walk.h"

/// <summary>
/// @Author : Oisin Wilson
/// </summary>


Jumping::Jumping()
{
}

Jumping::~Jumping()
{
}

void Jumping::idle(Animation* a)
{
	std::cout << "Jumping -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Jumping::walking(Animation * a)
{
	std::cout << "Jumping -> Walking" << std::endl;
	a->setCurrent(new Walk());
	delete this;
}