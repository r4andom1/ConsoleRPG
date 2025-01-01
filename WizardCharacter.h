#pragma once
#include "CharacterCreator.h"
#include <string>
using namespace std;

class WizardCharacter : public CharacterCreator
{
private:
	int m_maxHP;
	int m_currentHP;
	int m_baseDamage;

public:
	WizardCharacter(const string& name = "?", const string& pClass = "?", const string& race = "?", int maxHP = 5, int currentHP = 5, int baseDamage = 5);
	virtual ~WizardCharacter();

	// Member Functions
	string toString() const override;

	// Getters & Setters

};

