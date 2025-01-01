#include "WizardCharacter.h"

WizardCharacter::WizardCharacter(const string& name, const string& pClass, const string& race, int maxHP, int currentHP, int baseDamage)
	: CharacterCreator(name, pClass, race)
	, m_maxHP(maxHP)
	, m_currentHP(currentHP)
	, m_baseDamage(baseDamage)
{
}

WizardCharacter::~WizardCharacter()
{
}

string WizardCharacter::toString() const
{
	return CharacterCreator::toString() + "\nHealth: " + to_string(m_currentHP) + "/" + to_string(m_maxHP) +
		"\nDamage: " + to_string(m_baseDamage);

}