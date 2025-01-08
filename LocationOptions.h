#pragma once
#include "CharacterCreator.h"
#include "UtilityFunctions.h"
#include <string>

using namespace std;

class LocationOptions
{
private:

public:
	LocationOptions();
	~LocationOptions() = default;

	void startChurchLocation();
	void startCaveLocation();
	void displayChurchOptions() const;
};

