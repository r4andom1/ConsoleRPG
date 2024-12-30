#pragma once
#include "CharacterCreator.h"
#include <string>

using namespace std;

class Player : public CharacterCreator
{
private:
	int m_currentHP;
	int m_maxHP;
	int m_damage;

public:
	Player(int currentHP=-1, int maxHP=-1, int damage=-1,
		const string& name="?", const string& playerClass="?", const string& race="?");

};

