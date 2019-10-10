/// <summary>
/// @Author : Oisin Wilson
/// </summary>

#pragma once

#include "CommandInterface.h"
#include <iostream>
#include "Animation.h"

//Command list for each input

class UpOutput : public Command
{
public:
	virtual void execute() { Animation m_animation; m_animation.jumping(); }
};

class LeftOutput : public Command
{
public:
	virtual void execute() { Animation m_animation; m_animation.walking(); }
};

class RightOutput : public Command
{
public:
	virtual void execute() { Animation m_animation; m_animation.walking(); }
};

class ReleaseOutput : public Command
{
public:
	virtual void execute() { Animation m_animation; m_animation.idle(); }
};