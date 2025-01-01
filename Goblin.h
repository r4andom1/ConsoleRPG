#pragma once

#include "Creature.h"

class Goblin : public Creature
{
private:
    int m_damage;

public:
    Goblin(string name, int maxHealth, int level, int damage);

    bool isAlive() const override;

    void meleeAttack() const;

    int getDamage() const { return m_damage; }
    void setDamage(int damage) { m_damage = damage; }
};
