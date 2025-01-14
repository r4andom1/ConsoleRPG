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

void CreatureHandler::removeCreature(const string& name)
{
	for (int i = 0; i < m_currentNrOf; ++i)
	{
		if (m_creatures[i] && m_creatures[i]->getName() == name)
		{
			delete m_creatures[i];

			for (int j = i; j < m_currentNrOf - 1; ++j)
			{
				m_creatures[j] = m_creatures[j + 1];
			}

			m_creatures[--m_currentNrOf] = nullptr;
			return;
		}
	}
	cout << "Creature not found!" << endl;
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
	cout << "---------------------------" << endl;
}

Creature* CreatureHandler::getCreature(int index) const
{
	if (index < m_currentNrOf)
	{
		return m_creatures[index];
	}
	return nullptr;
}
