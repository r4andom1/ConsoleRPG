#include "FighterCharacter.h"

FighterCharacter::FighterCharacter(const string& name, const string& pClass, const string& race, int maxHP, int currentHP, int damage)
	: CharacterCreator(name, pClass, race, maxHP, currentHP, damage)
{
}

FighterCharacter::~FighterCharacter()
{
}

string FighterCharacter::toString() const
{
	return CharacterCreator::toString();
	// additional Fighter stats?
}
