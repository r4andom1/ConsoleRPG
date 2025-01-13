#include "FighterCharacter.h"

FighterCharacter::FighterCharacter(const string& name, const string& pClass, const string& race, int maxHP, int currentHP, int damage)
	: CharacterCreator(name, pClass, race, maxHP, currentHP, damage)
{
}

FighterCharacter::~FighterCharacter()
{
}

string FighterCharacter::toString() const
{
	return CharacterCreator::toString();
	// additional Fighter stats?
}

int FighterCharacter::attack()
{
	int basicAttack = getDamage();
	cout << "Fighter attacks for: " << basicAttack << " damage!" << endl;
	return basicAttack;
}

string FighterCharacter::drawPlayer() const
{

	return R"(
      _,.
    ,` -.)
   ( _/-\\-._
  /,|`--._,-^|            ,
  \_| |`-._/||          ,'|
    |  `-, / |         /  /
    |     || |        /  /
     `r-._||/   __   /  /
 __,-<_     )`-/  `./  /
'  \   `---'   \   /  /
    |           |./  /
    /           //  /
\_/' \         |/  /
 |    |   _,^-'/  /
 |    , ``  (\/  /_
  \,.->._    \X-=/^
  (  /   `-._//^`
   `Y-.____(__}
    |     {__)
          ()
	)";

}
