#include "Game.h"

Game::Game(CharacterCreator& character)
	: m_startGame(false)
	, m_character(&character) // nullptr? throws read access violation atm.
{
}

Game::~Game()
{
	delete m_character;
}

void Game::run()
{
	setStartGame(true);
	clearConsole();
	initPlayersClass();
	cout << "Game started inside Game Class with: " << endl;
	cout << m_character->toString() << endl; // Maybe enable this to work with dynamic binding?
	while (isRunning())
	{
		cout << "type 'q' to quit to start menu" << endl;
		cout << "type '3' to display character stats" << endl;
		char choice;
		cin >> choice;
		if (choice == 'q')
		{
			setStartGame(false);
		}
		else if (choice == '3')
		{
			cout << m_character->toString() << endl;
		}
	}
}

void Game::clearConsole()
{
	system("cls");
}

void Game::initPlayersClass()
{
	string name = m_character->getName();
	string race = m_character->getRace();
	string playerClass = m_character->getClass();
	if (playerClass == "Fighter")
		m_character = new FighterCharacter(name, playerClass, race);
	else if (playerClass == "Ranger")
		m_character = new RangerCharacter(name, playerClass, race);
	else
		m_character = new WizardCharacter(name, playerClass, race);
}
