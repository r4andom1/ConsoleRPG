#pragma once

#include "Location.h"
#include <vector>
#include <memory>
#include "Item.h"
#include "Inventory.h"

using namespace std;

class GameOptions
{
private:
	vector<shared_ptr<Location>> locations;
	shared_ptr<Location> currentLocation;

public:
	GameOptions();

	void travel();
	void inventory();
	void showStatistiks();
	void showCurrentLocation() const;
	void gameMenuStarter();
	void manageInventory(Inventory& inventory);

};