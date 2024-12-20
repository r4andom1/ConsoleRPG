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

	// Setters & Getters
	string getName() const { return this->m_name; }
	void setName(string name) { this->m_name = name; }
	string setClass() const { return this->m_class; }
	void getClass(string p_class) { this->m_class = p_class; }

};

