#pragma once
#include "StartMenu.h"
#include "CharacterCreator.h"
#include "FighterCharacter.h"
#include "Player.h"
#include "GameOptions.h"
#include <string>
using namespace std;

class Game
{
private:
	bool m_startGame;
	CharacterCreator* m_character; // changed these away from reference, maybe bad?

public:
	Game(CharacterCreator& character);
	virtual ~Game();

	// Member Functions
	void run();
	void clearConsole();
	void initPlayersClass();

	// Setters & Getters
	void setStartGame(bool startGame) { this->m_startGame = startGame; }
	bool isRunning() const { return this->m_startGame; }
};

