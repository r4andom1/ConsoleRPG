#pragma once
#include "Creature.h"
#include "Goblin.h"

class CreatureHandler
{
private:
	static const int m_maxCapacity = 10;
	int m_currentNrOf;
	Creature* m_creatures[m_maxCapacity];

public:
	// Constructor and destructor
	CreatureHandler(int currentNrOf=0);
	virtual ~CreatureHandler();

	// Member Functions
	bool addGoblin(const string& name, int damage, int maxHP, int currentHP, int level, bool isAlive=true);
	bool removeCreature(int index);

	// Getters & setters
	int getCreatureCount() const { return this->m_currentNrOf; }
	void displayAllCreatures();
	Creature* getCreature(int index) const;



};

