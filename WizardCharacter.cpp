#include "WizardCharacter.h"

WizardCharacter::WizardCharacter(const string& name, const string& pClass, const string& race, int maxHP, int currentHP, int damage, int mana)
	: CharacterCreator(name, pClass, race, maxHP, currentHP, damage)
	, m_mana(mana)
{
}

WizardCharacter::~WizardCharacter()
{
}

string WizardCharacter::toString() const
{
	return CharacterCreator::toString() +
		"\nMana: " + to_string(m_mana);
}

int WizardCharacter::castFireBall()
{
	int fireBallDamage = 10;
	cout << "Casting fireball for: " << fireBallDamage << endl;
	this->m_mana -= 3;
	return fireBallDamage;
}
