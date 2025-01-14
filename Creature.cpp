#include "Creature.h"
#include "CharacterCreator.h"

Creature::Creature(const string& name, int damage, int maxHP, int currentHP, int level, bool isAlive)
	: m_name(name)
	, m_damage(damage)
	, m_maxHP(maxHP)
	, m_currentHP(currentHP)
	, m_level(level)
	, m_isAlive(isAlive)
{
}

void Creature::takeDamage(int damageTaken)
{
	m_currentHP -= damageTaken;
	if (m_currentHP <= 0)
	{
		m_isAlive = false;
	}
}

bool Creature::isAlive() const
{
	return m_isAlive;
}

const int Creature::basicAttack()
{
	int baseDamage = this->getDamage();
	int levelBonus = this->getLevel();

	int damageDealt = baseDamage + levelBonus;

	return damageDealt;
}
