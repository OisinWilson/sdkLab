/// <summary>
/// @Author : Oisin Wilson
/// </summary>

#pragma once

#include"CommandManager.h"
#include"CommandInterface.h"

#include<stack>

#include <SDL.h>
#include <thread>
#include <SDL_image.h>


class InputHandeler
{
public:
	void inputHandle(SDL_Event & t_event, bool & t_running) {
		switch (t_event.type)
		{
		case SDL_KEYDOWN:
			switch (t_event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				t_running = false;
				break;
			case SDLK_UP:
				if (!m_keyStatePressed[0])
				{
					m_keyStatePressed[0] = true;
					m_manager.beginInput(buttonUp);
				}
				break;
			case SDLK_LEFT:
				if (!m_keyStatePressed[1])
				{
					m_keyStatePressed[1] = true;
					m_manager.beginInput(buttonLeft);
				}
				break;
			case SDLK_RIGHT:
				if (!m_keyStatePressed[2])
				{
					m_keyStatePressed[2] = true;
					m_manager.beginInput(buttonRight);
				}
				break;
			default:
				break;
			}
			break;
		case SDL_KEYUP:
			m_keyStatePressed[0] = false;
			m_keyStatePressed[1] = false;
			m_keyStatePressed[2] = false;
			m_manager.beginInput(releaseButton);
			break;
		}
	};

private:

	// handles the action the input should complete
	CommandManager m_manager;

	// each button used
	Command* buttonUp = new UpOutput();
	Command* buttonLeft = new LeftOutput();
	Command* buttonRight = new RightOutput();
	Command* releaseButton = new ReleaseOutput();

	// bools so theres one input per key release 
	bool m_keyStatePressed[4] = { false, false, false };
};