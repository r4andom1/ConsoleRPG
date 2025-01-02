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
	// This is just test code. Will replace with GameOptions class.
	cout << "Game started inside Game Class with: " << endl;
	cout << m_character->toString() << endl;
	gameoptions.gameMenuStarter();
}

void Game::clearConsole()
{
	system("cls");
}

/* */
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
