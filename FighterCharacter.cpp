#include "FighterCharacter.h"

FighterCharacter::FighterCharacter(const string& name, const string& pClass, const string& race, int maxHP, int currentHP, int baseDamage)
	: CharacterCreator(name, pClass, race)
	, m_maxHP(maxHP)
	, m_currentHP(currentHP)
	, m_baseDamage(baseDamage)
{
}

FighterCharacter::~FighterCharacter()
{
}

string FighterCharacter::toString() const
{
	return CharacterCreator::toString() + "\nHealth: " + to_string(m_currentHP) + "/" + to_string(m_maxHP) +
		"\nDamage: " + to_string(m_baseDamage);

}
