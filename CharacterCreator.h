#pragma once
#include <string>
#include <iostream>
#include "UtilityFunctions.h"
using namespace std;

class CharacterCreator
{
private:
	string m_name;
	string m_class;
	string m_race;
	int m_maxHP;
	int m_currentHP;
	int m_damage;
	int m_mana;
	bool m_isAlive;

public:
	// Constructor
	CharacterCreator(const string& name="?", const string& playerClass="?", const string& race="?",
	int maxHP=-1, int currentHP=-1, int damage=-1, int mana=0, bool isAlive=true);

	// Destructor
	virtual ~CharacterCreator() = default;

	// Member Functions
	virtual string toString() const;
	void createCharacter();
	string chooseName() const;
	string chooseClass() const;
	string chooseRace() const;
	void displayRaceOptions() const;
	void displayClassOptions() const;
	virtual int attack();
	void heal(int health);
	void takeDamage(int damageTaken);
	virtual string drawPlayer() const { return ""; };

	// Setters & Getters
	string getName() const { return this->m_name; }
	void setName(string name) { this->m_name = name; }
	string getClass() const { return this->m_class; }
	void setClass(string p_class) { this->m_class = p_class; }
	string getRace() const { return this->m_race; }
	void setRace(string race) { this->m_race = race; }
	int getMaxHP() const { return this->m_maxHP; }
	void setMaxHP(int maxHP) { this->m_maxHP = maxHP; }
	int getCurrentHP() const { return this->m_currentHP; }
	void setCurrentHP(int currentHP) { this->m_currentHP = currentHP; }
	int getDamage() const { return this->m_damage; }
	void setDamage(int damage) { this->m_damage = damage; }
	int getMana() const { return this->m_mana; }
	void setMana(int mana) { this->m_mana = mana; }
	bool isAlive() { return this->m_isAlive; }
	void setIsAlive(bool isAlive) { this->m_isAlive = isAlive; }
};

