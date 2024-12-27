#include "Game.h"

Game::Game()
	: m_startGame(false)
{
}

Game::~Game()
{
}

void Game::run()
{
	StartMenu menu;
	menu.start();
	if (menu.gameStarted())
	{
		//while (menu.)
		//{

		//}
	}
}
