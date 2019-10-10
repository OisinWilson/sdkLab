/// <summary>
/// @Author : Oisin Wilson
/// </summary>

#pragma once

//The template that the each command will take
class Command
{
public:
	virtual ~Command() {};
	virtual void execute() = 0;
protected:
	Command() {};
};