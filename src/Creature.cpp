#include "Creature.h"

Creature::Creature(const string& name, int damage, int maxHP, int currentHP, int level, bool isAlive)
	: m_name(name)
	, m_damage(damage)
	, m_maxHP(maxHP)
	, m_currentHP(currentHP)
	, m_level(level)
	, m_isAlive(isAlive)
{
}

string Creature::toString() const
{
	return m_name +
		"\nHP: " + to_string(m_currentHP) + "/" + to_string(m_maxHP) +
		"\nLevel: " + to_string(m_level);
}

void Creature::takeDamage(int damageTaken)
{
	m_currentHP -= damageTaken;
	if (m_currentHP <= 0)
	{
		m_isAlive = false;
	}
}
