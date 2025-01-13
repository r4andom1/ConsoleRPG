#pragma once
#include "CharacterCreator.h"
#include <string>
using namespace std;

class RangerCharacter : public CharacterCreator
{
private:

public:
	RangerCharacter(const string& name = "?", const string& pClass = "Ranger", const string& race = "?", int maxHP = 7, int currentHP = 7, int damage = 7);
	virtual ~RangerCharacter();

	// Member Functions
	string toString() const override;
	int attack() override;
	string drawPlayer() const override;

};