#include "RangerCharacter.h"

RangerCharacter::RangerCharacter(const string& name, const string& pClass, const string& race, int maxHP, int currentHP, int damage)
	: CharacterCreator(name, pClass, race, maxHP, currentHP, damage)
{
}

RangerCharacter::~RangerCharacter()
{
}

string RangerCharacter::toString() const
{
	return CharacterCreator::toString();
	// Additional Ranger stats?

}
