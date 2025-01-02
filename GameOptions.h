#pragma once

#include "Location.h"
#include "Item.h"
#include "Inventory.h"
#include "CharacterCreator.h"
#include <vector>
#include <memory>

using namespace std;

class GameOptions
{
private:
	vector<shared_ptr<Location>> locations;
	shared_ptr<Location> currentLocation;
	CharacterCreator* m_character;
	bool m_optionsRunning;

public:
	// Constructor
	GameOptions(CharacterCreator& character);

	// Destructor
	virtual ~GameOptions();

	// Member Functions
	void travel();
	void inventory();
	void showCharacterStats();
	void showCurrentLocation() const;
	void gameMenuStarter();
	void manageInventory(Inventory& inventory);

	// Getters & Setters
	bool isRunning() const { return this->m_optionsRunning; }
	void setIsRunning(bool isRunning) { this->m_optionsRunning = isRunning; }


};