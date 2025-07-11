#pragma once
#include "CharacterCreator.h"
#include <string>
using namespace std;

class RangerCharacter : public CharacterCreator
{
private:

public:
	RangerCharacter(const string& name = "?", const string& pClass = "Ranger", const string& race = "?", int maxHP = 12, int currentHP = 12, int damage = 7);
	virtual ~RangerCharacter();

	// Member Functions
	string toString() const override;
	int attack() override;
	string drawPlayer() const override;

};