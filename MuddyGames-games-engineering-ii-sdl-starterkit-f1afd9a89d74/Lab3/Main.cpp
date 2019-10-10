#include <thread>
#include <string>
#include<iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"

/// <summary>
/// @Author : Oisin Wilson
/// </summary>

int main(int argc, char** argv)
{
	Game* game = new Game();


	//Adjust screen positions as needed
	game->Initialize("SDL StarterKit", 300, 100, 800, 600, SDL_WINDOW_INPUT_FOCUS);

	game->LoadContent();

	while (game->IsRunning())
	{
		game->HandleEvents();
		game->Update();
		game->Render();
	}

	game->CleanUp();
	game->UnloadContent();

	return 0;
}