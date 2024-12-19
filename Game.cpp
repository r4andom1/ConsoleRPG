#include "Game.h"

Game::Game()
	: m_startGame(false)
	//, m_character(nullptr)
{
}

Game::~Game()
{
}

void Game::run()
{
	StartMenu menu;
	menu.start();
	if (menu.getCharacterCreated())
	{
		cout << "started game inside Game class" << endl;
	}
	
}
