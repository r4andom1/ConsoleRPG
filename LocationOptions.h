#pragma once
#include "CharacterCreator.h"
#include "Inventory.h"
#include "UtilityFunctions.h"
#include <string>
#include <iostream>
using namespace std;

class LocationOptions
{
private:
	CharacterCreator* m_character;
	Inventory* m_inventory;

public:
	LocationOptions(CharacterCreator& character, Inventory& inventory);
	~LocationOptions() = default;

	void startChurchLocation();
	void startCaveLocation();

	void displayChurchOptions() const;
	void displayCaveOptions() const;
};

