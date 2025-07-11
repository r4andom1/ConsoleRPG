#pragma once
#include "CharacterCreator.h"
#include <string>
#include <iostream>
using namespace std;

class WizardCharacter : public CharacterCreator
{
private:
	int m_mana;

public:
	WizardCharacter(const string& name="?", const string& pClass="Wizard", const string& race="?", int maxHP=10, int currentHP=10, int damage=10, int mana=10);
	virtual ~WizardCharacter();

	// Member Functions
	string toString() const override;
	int attack() override;
	string drawPlayer() const override;

	// Getters & Setters
	int getMana() const { return this->m_mana; }
	void setMana(int mana) { this->m_mana = mana; }

};

