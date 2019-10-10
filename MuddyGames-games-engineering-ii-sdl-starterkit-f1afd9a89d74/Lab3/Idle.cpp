#include "Idle.h"
#include "Jumping.h"
#include "Walk.h"

/// <summary>
/// @Author : Oisin Wilson
/// </summary>


Idle::Idle()
{
	// set y height for animaton

}

void Idle::handleInput() {}
void Idle::update() {}

void Idle::jumping(Animation* a)
{
	std::cout << "Idle -> Jumping" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}

void Idle::walking(Animation * a)
{
	std::cout << "Idle -> Walking" << std::endl;
	a->setCurrent(new Walk());
	delete this;
}
