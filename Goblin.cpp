#include "Goblin.h"

Goblin::Goblin(const string& name, int damage, int maxHP, int currentHP, int level, bool isAlive)
    : Creature(name, damage, maxHP, currentHP, level, isAlive)
{
}

const int Goblin::basicAttack()
{
    return 2;
}

void Goblin::drawCreature() const
{
    cout << "" << endl;
}

string Goblin::toString() const
{
    return Creature::toString();
}

void Goblin::takeDamage(int damageTaken)
{
    Creature::takeDamage(damageTaken);
}
