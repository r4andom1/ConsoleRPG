#include "WizardCharacter.h"

WizardCharacter::WizardCharacter(const string& name, const string& pClass, const string& race, int maxHP, int currentHP, int damage, int mana)
	: CharacterCreator(name, pClass, race, maxHP, currentHP, damage)
	, m_mana(mana)
{
}

WizardCharacter::~WizardCharacter()
{
}

string WizardCharacter::toString() const
{
	return CharacterCreator::toString() +
		"\nMana: " + to_string(m_mana);
}

int WizardCharacter::attack()
{
	if (m_mana >= 3)
	{
		int fireBallDamage = 10;
		cout << "Wizard casting fireball for: " << fireBallDamage << " damage!" << endl;
		cout << "-3 mana" << endl;
		this->m_mana -= 3;
		return fireBallDamage;
	}
	else
	{
		int basicAttack = getDamage();
		cout << "Wizard attacks with his staff for: " << basicAttack << " damage!" << endl;
		return basicAttack;
	}
}

string WizardCharacter::drawPlayer() const
{
	return R"(
              _,._      
  .||,       /_ _\\     
 \.`',/      |'L'| |    
 = ,. =      | -,| L    
 / || \    ,-'\"/,'`.   
   ||     ,'   `,,. `.  
   ,|____,' , ,;' \| |  
  (3|\    _/|/'   _| |  
   ||/,-''  | >-'' _,\\ 
   ||'      ==\ ,-'  ,' 
   ||       |  V \ ,|   
   ||       |    |` |   
   ||       |    |   \  
   ||       |    \    \ 
   ||       |     |    \
   ||       |      \_,-'
   ||       |___,,--")_\
   ||         |_|   ccc/
   ||        ccc/       
   ||                   
	)";
}

