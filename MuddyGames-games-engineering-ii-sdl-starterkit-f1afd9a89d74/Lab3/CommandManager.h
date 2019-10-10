/// <summary>
/// @Author : Oisin Wilson
/// </summary>

#pragma once

#include"ConcreteCommands.h"
#include <stack>

class CommandManager
{
public:
	void beginInput(Command* t_input) {
		m_commands.push(t_input);
		execute();
	}
	virtual void remove() { m_commands.pop(); }
	virtual void execute() { m_commands.top()->execute(); }

private:
	std::stack<Command*> m_commands;
};