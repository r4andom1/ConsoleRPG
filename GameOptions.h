#pragma once

#include "Location.h"
#include "Item.h"
#include "Inventory.h"
#include "CharacterCreator.h"
#include "LocationOptions.h"
#include "UtilityFunctions.h"
#include <vector>
#include <memory>

using namespace std;

class GameOptions
{
private:
	vector<shared_ptr<Location>> locations;
	shared_ptr<Location> currentLocation;
	CharacterCreator* m_character;
	unique_ptr<Inventory> m_inventory;
	LocationOptions m_locationOptions;
	bool m_optionsRunning;
	bool m_firstPlaythrough;

public:
	// Constructor
	GameOptions(CharacterCreator& character);

	// Destructor
	virtual ~GameOptions();

	// Member Functions
	void travel();
	void showCharacterStats();
	void gameMenuStarter();
	void manageInventory(Inventory& inventory);
	void displayGameOptions() const;
	void startingAreaDescription() const;

	// Getters & Setters
	bool isRunning() const { return this->m_optionsRunning; }
	void setIsRunning(bool isRunning) { this->m_optionsRunning = isRunning; }
	void setFirstPlaythrough(bool firstPlay) { this->m_firstPlaythrough = firstPlay; }
	bool getFirstPlaythrough() const { return this->m_firstPlaythrough; }
};