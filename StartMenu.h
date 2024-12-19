#pragma once
#include "Game.h"
#include "CharacterTemplate.h"
#include "CharacterCreator.h"
#include <iostream>
#include <string> 
#include <thread> // sleep functionality
#include <chrono> // sleep functionality
using namespace std;

class StartMenu
{
private:
	bool m_startMenu;
	bool m_startGame;
	bool m_characterCreated;

public:
	StartMenu();
	virtual ~StartMenu();

	// Member Functions
	void start();
	void displayChoices() const;
	char userChoice() const;
	void menuChoice(char choice);
	void clearConsole();
	void sleepTimer(int seconds);

	// Setters & Getters
	void setStartMenu(bool startMenu) { this->m_startMenu = startMenu; }
	bool isRunning() const { return this->m_startMenu; }
	void setStartGame(bool startGame) { this->m_startGame = startGame; }
	bool gameStarted() const { return this->m_startGame; }
	void setCharacterCreated(bool characterCreated) { this->m_characterCreated = characterCreated; }
	bool getCharacterCreated() const { return this->m_characterCreated; }

};

