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
	// The Character is now finally represented inside the game!
	setStartGame(true);
	cout << "Game started inside Game Class with: " << endl;
	cout << m_character.toString() << endl;
	while (isRunning())
	{
		cout << "type 'q' to quit" << endl;
		char choice;
		cin >> choice;
		if (choice == 'q')
		{
			setStartGame(false);
		}
	}
}
