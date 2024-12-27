#include "CharacterCreator.h"


CharacterCreator::CharacterCreator(const string& name, string playerClass)
	: m_name(name)
	, m_class(playerClass)
{
}

CharacterCreator::~CharacterCreator()
{
}

void CharacterCreator::start()
{
}

string CharacterCreator::toString() const
{
	return "\nName: " + m_name + "\nClass: " + m_class;
}

 //Testing characterCreator for easier debugging
void CharacterCreator::createCharacter()
{
	setName("TestGuy");
	setClass("Fighter");
}

// Final CharacterCreator function when playing the finished game.
//void CharacterCreator::createCharacter()
//{
//	setName(chooseName());
//	setClass(chooseClass());
//}

string CharacterCreator::chooseName() const
{
	cout << "Enter a name for your character: ";
	string name{};
	cin >> name;
	return name;
}

string CharacterCreator::chooseClass() const
{
	displayClassInfo();
	char classChosen = userChoice();
	if (classChosen == '1')
	{
		return "Fighter";
	}
	else if (classChosen == '2')
	{
		return "Ranger";
	}
	else if (classChosen == '3')
	{
		return "Wizard";
	}
	else
	{
		cout << "Enter a valid class from 1-3" << endl;
	}
}

void CharacterCreator::displayClassInfo() const
{
	cout << "Choose which class you want to play as: " << endl;
	cout << "1) Fighter" << endl;
	cout << "2) Ranger" << endl;
	cout << "3) Wizard" << endl;
}

char CharacterCreator::userChoice() const
{
	cout << "Enter your choice : " << endl;
	char choice{};
	cin >> choice;
	if (!cin)
	{
		cin.clear();
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return choice;
}