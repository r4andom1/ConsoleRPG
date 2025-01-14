#include "CreatureHandler.h"

CreatureHandler::CreatureHandler(int currentNrOf)
	: m_currentNrOf(currentNrOf)
	, m_creatures{ nullptr }
{
}

CreatureHandler::~CreatureHandler()
{
	for (int i = 0; i < m_currentNrOf; i++)
	{
		delete m_creatures[i];
	}
}

bool CreatureHandler::addGoblin(const string& name, int damage, int maxHP, int currentHP, int level, bool isAlive)
{
	bool didAdd = false;
	if (m_currentNrOf < m_maxCapacity)
	{
		m_creatures[m_currentNrOf++] = new Goblin(name, damage, maxHP, currentHP, level);
		didAdd = true;
	}
	return didAdd;
}

bool CreatureHandler::removeCreature(int index)
{
	bool didRemove = false;
	if (index < m_maxCapacity)
	{
		delete m_creatures[index];
		m_creatures[index] = nullptr;
		--m_currentNrOf;
		didRemove = true;
	}
	return didRemove;
}

void CreatureHandler::displayAllCreatures()
{
	if (m_currentNrOf > 0)
	{
		for (int i = 0; i < m_currentNrOf; i++)
		{
			cout << to_string(i + 1) << ") ";
			cout << m_creatures[i]->toString() << endl;
			cout << endl;
		}
	}
}

Creature* CreatureHandler::getCreature(int index) const
{
	if (index < m_currentNrOf)
	{
		return m_creatures[index];
	}
	return nullptr;
}
