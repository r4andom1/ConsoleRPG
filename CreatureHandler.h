#pragma once

#include "Creature.h"

using namespace std;

class CreatureHandler
{
private:
    Creature** m_creatures;
    int m_capacity;
    int m_size;

    void expand();

public:
    CreatureHandler();
    ~CreatureHandler();

    // Member Functions
    void addCreature(Creature* creature);
    void removeCreature(const string& name);
    void setCreatureHP(const string& name, int newHP);
    void listCreatures() const;
    Creature* getCreature(int index) const;
    int getCreatureCount() const;
};