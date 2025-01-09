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
