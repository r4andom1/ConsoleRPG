#pragma once
#include "CharacterCreator.h"
#include "Location.h"
#include "UtilityFunctions.h"
#include <string>

using namespace std;

class LocationOptions : public Location
{
private:

public:
	LocationOptions(Location& location);
	~LocationOptions() = default;

	void startChurchLocation();
	void startCaveLocation();
	void displayChurchOptions() const;
};

