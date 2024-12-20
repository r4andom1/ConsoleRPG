#include "Game.h"

Game::Game(CharacterCreator* character)
	: m_startGame(false)
	, m_character(nullptr)
{
}

Game::~Game()
{
}

void Game::run()
{
	StartMenu menu;
	menu.start();
}
