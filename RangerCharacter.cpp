#include "RangerCharacter.h"

RangerCharacter::RangerCharacter(const string& name, const string& pClass, const string& race, int maxHP, int currentHP, int damage)
	: CharacterCreator(name, pClass, race, maxHP, currentHP, damage)
{
}

RangerCharacter::~RangerCharacter()
{
}

string RangerCharacter::toString() const
{
	return CharacterCreator::toString();
	// Additional Ranger stats?

}

int RangerCharacter::attack()
{
	int basicAttack = getDamage();
	cout << "Ranger draws his bow and hits for: " << basicAttack << " damage!" << endl;
	return basicAttack;
}

string RangerCharacter::drawPlayer() const
{
	return R"(
                 .,
        .    ____/__,
      .' \  / \==\```
     /    \ 77 \ |
    /_.----\\__,-----.
<--(\_|_____<__|_____/
    \  ````/|   ``/```
     `.   / |    I|
       `./  |____I|
            !!!!!!!
            | | I |
            | | I |
            \ \ I |
            | | I |
           _|_|_I_|
          /__/____|
	)";
}
