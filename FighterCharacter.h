#pragma once
#include "CharacterCreator.h"
#include <iostream>
#include <string>
using namespace std;

class FighterCharacter : public CharacterCreator
{
private:

public:
	FighterCharacter(const string &name="?", const string& pClass="Fighter", const string& race="?", int maxHP=10, int currentHP=10, int damage=5);
	virtual ~FighterCharacter();

	// Member Functions
	string toString() const override;
	int attack() override;
};

