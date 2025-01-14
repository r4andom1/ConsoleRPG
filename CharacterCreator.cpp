#include "CharacterCreator.h"

CharacterCreator::CharacterCreator(const string& name, const string& playerClass, const string& race,
	int maxHP, int currentHP, int damage, int mana, bool isAlive)
	: m_name(name)
	, m_class(playerClass)
	, m_race(race)
	, m_maxHP(maxHP)
	, m_currentHP(currentHP)
	, m_damage(damage)
	, m_mana(mana)
	, m_isAlive(isAlive)
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
	return "\nName: " + m_name +
		   "\nClass: " + m_class +
		   "\nRace: " + m_race +
		   "\nHealth: " + to_string(m_currentHP) + "/" + to_string(m_maxHP) +
	       "\nDamage: " + to_string(m_damage);
}

/* Testing characterCreator for easier debugging */
//void CharacterCreator::createCharacter()
//{
//	setName("TestGuy");
//	setClass("Fighter");
//	setRace("Human");
//	cout << "Test character created successfully" << endl;
//}

/* Final CharacterCreator function when playing the finished game */
void CharacterCreator::createCharacter()
{
	setName(chooseName());
	UtilityFunctions::clearConsole();
	setClass(chooseClass());
	setRace(chooseRace());
	cout << "Player-defined character created successfully" << endl;
}

string CharacterCreator::chooseName() const
{
	cout << "Enter a name for your character: ";
	string name{};
	cin >> name;
	return name;
}

string CharacterCreator::chooseClass() const
{
	displayClassOptions();
	char classChosen = UtilityFunctions::userChoice();
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

string CharacterCreator::chooseRace() const
{
	displayRaceOptions();
	char raceChosen = UtilityFunctions::userChoice();
	if (raceChosen == '1')
	{
		return "Human";
	}
	else if (raceChosen == '2')
	{
		return "Elf";
	}
	else if (raceChosen == '3')
	{
		return "Dwarf";
	}
	else
	{
		cout << "Enter a valid race from 1-3" << endl;
	}
}

void CharacterCreator::displayRaceOptions() const
{
	cout << "Choose which race you want to play as: " << endl;
	cout << "1) Human" << endl;
	cout << "2) Elf" << endl;
	cout << "3) Dwarf" << endl;
}

void CharacterCreator::displayClassOptions() const
{
	cout << "Choose which class you want to play as: " << endl;
	cout << "1) Fighter" << endl;
	cout << "2) Ranger" << endl;
	cout << "3) Wizard" << endl;
}

int CharacterCreator::attack()
{
	return m_damage;
}

void CharacterCreator::heal(int health)
{
	int newHealth = m_currentHP + health;
	if (newHealth <= m_maxHP)
		m_currentHP = newHealth;
	else
		m_currentHP = m_maxHP;
}

void CharacterCreator::takeDamage(int damageTaken)
{
	m_currentHP -= damageTaken;
	if (m_currentHP <= 0)
	{
		m_isAlive = false;
	}
}