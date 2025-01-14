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
	bool m_caveQuestCompleted;
	bool m_firstEncounterWithPriest;
	Inventory* m_inventory;
	CombatOptions* m_combatoptions;
	CharacterCreator* m_charactercreator;

public:
	LocationOptions(CharacterCreator& character, Inventory& inventory);
	~LocationOptions() = default;
	
	void startChurchLocation();
	void displayChurchOptions() const;
	void priestDialogueChoice();
	void priestDialogueOptions() const;
	void firstEncounterPriest();

	void startCaveLocation();
	void initializeCombatOptions(CreatureHandler& creatureHandler);
	void displayCaveOptions() const;

	// Setters & getters
	void setFirstEncounterWithPriest(bool firstEncounter) { this->m_firstEncounterWithPriest = firstEncounter; }
	void setCaveQuestCompleted(bool completed) { this->m_caveQuestCompleted = completed; }

};

