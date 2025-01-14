#pragma once
#include "CharacterCreator.h"
#include "UtilityFunctions.h"
#include "CreatureHandler.h"
#include "Inventory.h"
#include <string>
#include <iostream>

using namespace std;

class CombatOptions
{
private:
	CharacterCreator* m_character;
	Inventory* m_inventory;
	CreatureHandler& m_creatureHandler;

public:
	CombatOptions(CreatureHandler& creatureHandler, CharacterCreator& character, Inventory& inventory);
	virtual ~CombatOptions();

	void startCombatLoop();
	void attackCreature();
};

