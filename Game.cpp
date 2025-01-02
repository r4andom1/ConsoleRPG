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
	GameOptions gameOptions(*m_character);
	gameOptions.gameMenuStarter();
}

void Game::clearConsole()
{
	system("cls");
}

/* Initializes the correct CharacterClass inside the Game */
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
