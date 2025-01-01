#pragma once
#include <iostream>
#include <string>

using namespace std;

class Creature
{
private:
	string m_name;
	int m_maxHealth;
	int m_currentHealth;
	int m_level;

public:
	virtual ~Creature() {};

	virtual bool isAlive() const = 0;

	string getName() const { return m_name; }
	void setName(string name) { this->m_name = name; }
	int getMaxHealth() const { return m_maxHealth; }
	void setMaxHealth(int maxHealth) { this->m_maxHealth = maxHealth; }
	int getCurrentHealth() const { return m_currentHealth; }
	void setCurrentHealth(int currentHealth) { this->m_currentHealth = currentHealth; }
	int getLevel() const { return m_level; }
	void setLevel(int level) { this->m_level = level; }


};