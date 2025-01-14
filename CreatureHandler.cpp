#include "CreatureHandler.h"
#include <iostream>
#include <algorithm>

CreatureHandler::CreatureHandler()
    : m_creatures(new Creature*[m_capacity]{nullptr})
    , m_capacity(5)
    , m_size(0)
{
}

CreatureHandler::~CreatureHandler()
{
    for (int i = 0; i < m_size; ++i)
    {
        delete m_creatures[i];
    }
    delete[] m_creatures;
}

void CreatureHandler::expand()
{
    m_capacity *= 2;
    Creature** newArray = new Creature * [m_capacity];

    for (int i = 0; i < m_size; ++i)
    {
        newArray[i] = m_creatures[i];
    }

    delete[] m_creatures;
    m_creatures = newArray;
}

void CreatureHandler::addCreature(Creature* creature)
{
    if (m_size == m_capacity)
    {
        expand();
    }

    m_creatures[m_size++] = creature;
    cout << "Creature added successfully!" << endl;
}

void CreatureHandler::removeCreature(const string& name)
{
    for (int i = 0; i < m_size; ++i)
    {
        if (m_creatures[i]->getName() == name)
        {
            delete m_creatures[i]; // Rensa upp minnet för den borttagna creaturen

            // Flytta resten av arrayen för att fylla hålet
            for (int j = i; j < m_size - 1; ++j)
            {
                m_creatures[j] = m_creatures[j + 1];
            }

            --m_size; // Minska storleken
            cout << "Creature removed successfully!" << endl;
            return;
        }
    }
    cout << "Creature not found!" << endl;
}

void CreatureHandler::setCreatureHP(const string& name, int newHP)
{
    for (int i = 0; i < m_size; ++i)
    {
        if (m_creatures[i]->getName() == name)
        {
            m_creatures[i]->setCurrentHealth(newHP);
            cout << "HP updated for " << name << " to " << newHP << "!" << endl;
            return;
        }
    }
    cout << "Creature not found!" << endl;
}

void CreatureHandler::listCreatures() const
{
    if (m_size == 0)
    {
        cout << "No creatures in the handler!" << endl;
        return;
    }

    cout << "Listing all creatures:" << endl;
    for (int i = 0; i < m_size; ++i)
    {
        cout << "Name: " << m_creatures[i]->getName()
            << ", HP: " << m_creatures[i]->getCurrentHealth()
            << ", Level: " << m_creatures[i]->getLevel()
            << endl;
    }
}

Creature* CreatureHandler::getCreature(int index) const
{
    if (index >= 0 && index < m_size)
    {
        return m_creatures[index];
    }
    return nullptr;
}

int CreatureHandler::getCreatureCount() const
{
    return m_size;
}

