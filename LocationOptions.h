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
	bool m_caveQuestCompleted;
	bool m_firstEncounterWithPriest;

public:
	LocationOptions(CharacterCreator& character, Inventory& inventory);
	~LocationOptions() = default;

	void startChurchLocation();
	void startCaveLocation();
	void displayChurchOptions() const;
	void priestDialogueChoice();
	void priestDialogueOptions() const;
	void firstEncounterPriest();

	// Setters & getters
	void setFirstEncounterWithPriest(bool firstEncounter) { this->m_firstEncounterWithPriest = firstEncounter; }
	void setCaveQuestCompleted(bool completed) { this->m_caveQuestCompleted = completed; }
};

