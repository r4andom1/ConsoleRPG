#pragma once

#include "LocationOptions.h"
#include "CharacterCreator.h"
#include "UtilityFunctions.h"
#include "Inventory.h"
#include <string>
#include <iostream>

using namespace std;

class LocationOptions; // Forward declaration solves it??

class CombatOptions
{
private:
	CharacterCreator* m_character;
	Inventory* m_inventory;
	LocationOptions* m_locationOptions;

public:
	CombatOptions(CharacterCreator& character, Inventory& inventory, LocationOptions& locationOptions);
	void startCombatLoop();
};

