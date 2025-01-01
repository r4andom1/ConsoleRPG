#include "Goblin.h"

Goblin::Goblin(string name, int maxHealth, int level, int damage)
{
    setName(name);
    setMaxHealth(maxHealth);
    setCurrentHealth(maxHealth);
    setLevel(level);
    m_damage = damage;
}

bool Goblin::isAlive() const
{
    return getCurrentHealth() > 0;
}

void Goblin::meleeAttack() const
{
    cout << getName() << " attacks for " << m_damage << " damage!" << endl;
}
