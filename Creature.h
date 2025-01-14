#pragma once
#include <iostream>
#include <string>

using namespace std;

class Creature // abstract class
{
private:
	string m_name;
	int m_damage;
	int m_maxHP;
	int m_currentHP;
	int m_level;
	bool m_isAlive;

public:
	// Cons and dest
	Creature(const string& name, int damage, int maxHP, int currentHP, int level, bool isAlive);
	virtual ~Creature() = default;
	
	// Member Functions
	const virtual int basicAttack() = 0;
	virtual void drawCreature() const = 0;
	virtual string toString() const = 0;
	virtual void takeDamage(int damageTaken) = 0;

	// Getters & setters
	string getName() const { return m_name; }
	void setName(string name) { this->m_name = name; }
	int getDamage() const { return this->m_damage; }
	void setDamage(int damage) { this->m_damage = damage; }
	int getMaxHealth() const { return m_maxHP; }
	void setMaxHealth(int maxHealth) { this->m_maxHP = maxHealth; }
	int getCurrentHealth() const { return m_currentHP; }
	void setCurrentHealth(int currentHealth) { this->m_currentHP = currentHealth; }
	int getLevel() const { return m_level; }
	void setLevel(int level) { this->m_level = level; }
	bool isAlive() const { return this->m_isAlive; }
	
};