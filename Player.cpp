#include "Player.h"

Player::Player(int currentHP, int maxHP, int damage,
		const string& name, const string& playerClass, const string& race)
	: CharacterCreator(name, playerClass, race)
	, m_currentHP(currentHP)
	, m_maxHP(maxHP)
	, m_damage(damage)
{
}
