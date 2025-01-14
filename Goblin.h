#pragma once

#include "Creature.h"
#include <string>
#include <iostream>
using namespace std;

class Goblin : public Creature
{
private:

public:
    Goblin(const string& name, int damage, int maxHP, int currentHP, int level, bool isAlive=true);
    virtual ~Goblin() = default;

    // Inherited via Creature
    const int basicAttack() override;
    void drawCreature() const override;
    string toString() const override;
    void takeDamage(int damageTaken) override;

};
