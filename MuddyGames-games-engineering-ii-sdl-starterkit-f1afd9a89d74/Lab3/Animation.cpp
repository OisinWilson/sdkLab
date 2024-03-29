#include "Animation.h"

#include "Idle.h"


/// <summary>
/// @Author : Oisin Wilson
/// </summary>


Animation::Animation()
{
	m_current = new Idle();
}

Animation::~Animation() {}

void Animation::setCurrent(State* s)
{
	m_current = s;
}

State* Animation::getCurrent()
{
	return m_current;
}

void Animation::setPrevious(State* s)
{
	m_previous = s;
}

State* Animation::getPrevious()
{
	return m_previous;
}

void Animation::idle()
{
	m_current->idle(this);
}

void Animation::jumping()
{
	m_current->jumping(this);
}


void Animation::walking()
{
	m_current->walking(this);
}