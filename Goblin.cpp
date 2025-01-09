#include "Goblin.h"

Goblin::Goblin(const string& name, int damage, int maxHP, int currentHP, int level, bool isAlive)
    : Creature(name, damage, maxHP, currentHP, level, isAlive)
{
}
