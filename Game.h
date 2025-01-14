#pragma once
#include "StartMenu.h"
#include "CharacterCreator.h"
#include "FighterCharacter.h"
#include "RangerCharacter.h"
#include "WizardCharacter.h"
#include "UtilityFunctions.h"
#include "GameOptions.h"
#include <string>
using namespace std;

class Game
{
private:
	bool m_startGame;
	CharacterCreator* m_character;

public:
	Game(CharacterCreator& character);
	virtual ~Game();

	// Member Functions
	void run();
	void initPlayersClass();

	// Setters & Getters
	void setStartGame(bool startGame) { this->m_startGame = startGame; }
	bool isRunning() const { return this->m_startGame; }
};

