#pragma once
#include "CharacterCreator.h"
#include <string>
using namespace std;

class RangerCharacter : public CharacterCreator
{
private:
	int m_maxHP;
	int m_currentHP;
	int m_baseDamage;

public:
	RangerCharacter(const string& name = "?", const string& pClass = "?", const string& race = "?", int maxHP = 7, int currentHP = 7, int baseDamage = 7);
	virtual ~RangerCharacter();

	// Member Functions
	string toString() const override;

	// Getters & Setters

};