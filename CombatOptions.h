#pragma once
#include "CharacterCreator.h"
#include "UtilityFunctions.h"
#include "Inventory.h"
#include <string>
#include <iostream>

using namespace std;

class CombatOptions
{
private:
	CharacterCreator* m_character;
	Inventory* m_inventory;

public:
	CombatOptions(CharacterCreator& character, Inventory& inventory);
	void startCombatLoop();
};

