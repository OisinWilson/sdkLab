#include "Walk.h"
#include "Idle.h"
#include "Jumping.h"

/// <summary>
/// @Author : Oisin Wilson
/// </summary>

Walk::Walk()
{
}


Walk::~Walk()
{
}


void Walk::idle(Animation * a)
{
	std::cout << "Walking -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}


void Walk::jumping(Animation * a)
{
	std::cout << "Walking -> Jumping" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}