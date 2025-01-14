#pragma once
#include "Creature.h"

class Goblin : public Creature
{
private:

public:
    Goblin(const string& name, int damage, int maxHP, int currentHP, int level, bool isAlive=true);
    virtual ~Goblin() = default;
};
