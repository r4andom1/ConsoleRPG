#include "Game.h"

Game::Game(CharacterCreator& character)
	: m_startGame(false)
	, m_character(character)
{
}

Game::~Game()
{
}

void Game::run()
{
	cout << m_character.toString() << endl;

}
