#pragma once
#include <string>
#include <iostream>
using namespace std;

class CharacterCreator
{
private:
	string m_name;
	string m_class;

public:
	CharacterCreator(const string& name="?", string playerClass="?");
	virtual ~CharacterCreator();

	// Member Functions
	void start();
	string toString() const;
	void createCharacter();
	string chooseName() const;
	string chooseClass() const;
	void displayClassInfo() const;
	char userChoice() const;

	// Setters & Getters
	string getName() const { return this->m_name; }
	void setName(string name) { this->m_name = name; }
	string getClass() const { return this->m_class; }
	void setClass(string p_class) { this->m_class = p_class; }

};

