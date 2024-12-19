#pragma once
#include "StartMenu.h"
#include "CharacterTemplate.h"
#include <string>
using namespace std;


class Game
{
private:
	bool m_startGame;
	//CharacterTemplate* m_character; // pass values into this object?

public:
	Game();
	virtual ~Game();

	// Member Functions
	void run();

	// Setters & Getters
	void setStartGame(bool startGame) { this->m_startGame = startGame; }
	bool isRunning() const { return this->m_startGame; }
};

