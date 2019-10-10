
#include <iostream>
#include <thread>
#include "Game.h"

/// <summary>
/// @Author : Oisin Wilson
/// </summary>


Game::Game() : m_running(false)
{
	testAn.m_maxFrames = 5;
	testAn.m_oscillate = true;
	spriteHeight = 25;
}

Game::~Game()
{
}

bool Game::Initialize(const char* title, int xpos, int ypos, int width, int height, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL Init success" << std::endl;
		m_p_Window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (m_p_Window != 0)
		{
			std::cout << "Window creation success" << std::endl;
			m_p_Renderer = SDL_CreateRenderer(m_p_Window, -1, 0);
			if (m_p_Renderer != 0)
			{
				std::cout << "Renderer creation success" << std::endl;
				SDL_SetRenderDrawColor(m_p_Renderer, 255, 255, 255, 255);
			}
			else
			{
				std::cout << "Renderer init fail" << std::endl;
				return false;
			}
		}
		else
		{
			std::cout << "Window init fail" << std::endl;
			return false;
		}
	}
	else
	{
		std::cout << "SDL Init fail" << std::endl;
		return false;
	}
	m_running = true;

	return true;
}



void Game::LoadContent()
{
	std::cout << "Loading Content" << std::endl;
	m_p_Surface = SDL_LoadBMP("assets/stick.bmp");
	m_p_Texture = SDL_CreateTextureFromSurface(m_p_Renderer, m_p_Surface);
	//SDL_FreeSurface(m_p_Surface);

	if (SDL_QueryTexture(m_p_Texture, NULL, NULL, &m_Source.w, &m_Destination.h) == 0)
	{
		m_Destination.x = m_Source.x = 0;
		m_Destination.y = m_Source.y = 0;
		m_Destination.w = m_Source.w;
		m_Destination.h = m_Source.h;
	}
	else
	{
		std::cout << "Texture Query Failed" << std::endl;
		m_running = false;
	}
}

void Game::Render()
{
	SDL_RenderClear(m_p_Renderer);

	//OnDraw(SDL_GetWindowSurface(m_p_Window), m_p_Surface, 25, 25, 25, 25, 125, 125);


	OnDraw(SDL_GetWindowSurface(m_p_Window), m_p_Surface, 25, 25, testAn.GetCurrentFrame() * 125 + 25, spriteHeight, 125, 125);

	SDL_UpdateWindowSurface(m_p_Window);
}

void Game::Update()
{
	testAn.OnAnimate();
	//DEBUG_MSG("Updating....");
}

void Game::HandleEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		m_inputs.inputHandle(event,m_running);
	}
}

bool Game::IsRunning()
{
	return m_running;
}

void Game::UnloadContent()
{
}

void Game::CleanUp()
{
	SDL_DestroyWindow(m_p_Window);
	SDL_DestroyRenderer(m_p_Renderer);
	SDL_Quit();
}

void Game::OnDraw(SDL_Surface * Surf_Dest, SDL_Surface * Surf_Src, int X, int Y)
{
	//if (Surf_Dest == NULL || Surf_Src == NULL) {
	//	return false;
	//}

	SDL_Rect DestR;

	DestR.x = X;
	DestR.y = Y;

	SDL_BlitSurface(Surf_Src, NULL, Surf_Dest, &DestR);

	//return true;
}

// x pos on screen
// y pos on screen
// x pos on image
// y pos on image
// with of rect
// height of rect
void Game::OnDraw(SDL_Surface * Surf_Dest, SDL_Surface * Surf_Src, int X, int Y, int X2, int Y2, int W, int H)
{
	//if (Surf_Dest == NULL || Surf_Src == NULL) {
	//	return false;
	//}

	SDL_Rect DestR;

	DestR.x = X;
	DestR.y = Y;

	SDL_Rect SrcR;

	SrcR.x = X2;
	SrcR.y = Y2;
	SrcR.w = W;
	SrcR.h = H;

	SDL_BlitSurface(Surf_Src, &SrcR, Surf_Dest, &DestR);

	//return true;
}
