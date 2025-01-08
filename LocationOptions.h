#pragma once
#include "CharacterCreator.h"
#include "Inventory.h"
#include "UtilityFunctions.h"
#include "CombatOptions.h"
#include <string>

using namespace std;

class LocationOptions
{
private:
	CharacterCreator* m_character;
	Inventory* m_inventory;
	unique_ptr<CombatOptions> m_combatoptions;

public:
	LocationOptions(CharacterCreator& character, Inventory& inventory);
	~LocationOptions() = default;

	void startChurchLocation();
	void startCaveLocation();

	void displayChurchOptions() const;
	void displayCaveOptions() const;
};

