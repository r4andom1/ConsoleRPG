#pragma once
#include "CharacterCreator.h"
#include <string>
using namespace std;

class FighterCharacter : public CharacterCreator
{
private:
	int m_maxHP;
	int m_currentHP;
	int m_baseDamage;

public:
	FighterCharacter(const string &name="?", const string& pClass="?", const string& race="?", int maxHP=10, int currentHP=10, int baseDamage=5);
	virtual ~FighterCharacter();

	// Member Functions
	string toString() const override;

	// Getters & Setters

};

