#include "Goblin.h"

Goblin::Goblin(const string& name, int damage, int maxHP, int currentHP, int level, bool isAlive)
    : Creature(name, damage, maxHP, currentHP, level, isAlive)
{
}

const int Goblin::basicAttack()
{
    int baseDamage = this->getDamage();
    int levelBonus = this->getLevel();

    int damageDealt = baseDamage + levelBonus;

    return damageDealt;
}
