#pragma once
#include "CharacterCreator.h"
#include <string>
using namespace std;

class WizardCharacter : public CharacterCreator
{
private:
	int m_mana;

public:
	WizardCharacter(const string& name="?", const string& pClass="Wizard", const string& race="?", int maxHP=5, int currentHP=5, int damage=5, int mana=10);
	virtual ~WizardCharacter();

	// Member Functions
	string toString() const override;
	int castFireBall();

	// Getters & Setters

};

