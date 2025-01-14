#include "CombatOptions.h"
#include "Goblin.h"

CombatOptions::CombatOptions(CreatureHandler& creatureHandler, CharacterCreator& character, Inventory& inventory)
    : m_creaturehandler(&creatureHandler), m_character(&character), m_inventory(&inventory)
{
    if (m_creaturehandler == nullptr) {
        cout << "CreatureHandler is not initialized properly!" << endl;
        return;
    } 
    if (m_character == nullptr) {
        cout << "CharacterCreator is not initialized properly!" << endl;
        return;
    }
    if (m_inventory == nullptr) {
        cout << "Inventory is not initialized properly!" << endl;
        return;
    }

    m_creaturehandler->addCreature(new Goblin("Goblin Warrior", 3, 6, 6, 2, true));
    m_creaturehandler->addCreature(new Goblin("Goblin Archer", 4, 5, 5, 2, true));

}

void CombatOptions::startCombatLoop()
{
    bool isRunning = true;

    while (isRunning)
    {
        cout << "\n--- Combat Menu ---\n";
        cout << "1. Attack" << endl;
        cout << "2. View Inventory" << endl;
        cout << "3. View Stats" << endl;
        cout << "4. View Remaining Creatures" << endl;
        cout << "q. Exit" << endl;

        char choice = UtilityFunctions::userChoice();

        if (choice == '1')
        {
            attackCreature();
        }
        else if (choice == '2')
        {
            cout << "Opening inventory...\n";
            m_inventory->manageInventory();
            m_inventory->saveToFile();
        }
        else if (choice == '3')
        {
            cout << m_character->toString() << endl;
        }
        else if (choice == '4')
        {
            if (m_creaturehandler) {
                m_creaturehandler->listCreatures();
            }
            else {
                cout << "CreatureHandler is not initialized!" << endl;
            }
        }
        else if (choice == 'q')
        {
            isRunning = false;
        }
        else
        {
            cout << "Invalid choice! Try again.\n";
        }

        if (isRunning)
        {
            UtilityFunctions::confirmToContinue();
        }
    }
}

void CombatOptions::attackCreature()
{
    if (!m_creaturehandler) {
        cout << "CreatureHandler is not initialized!" << endl;
        return;
    }

    if (m_creaturehandler->getCreatureCount() == 0)
    {
        cout << "No creatures to attack!" << endl;
        return;
    }

    cout << "Choose a creature to attack:\n";
    m_creaturehandler->listCreatures();

    int index;
    cout << "Enter the creature index (0-" << m_creaturehandler->getCreatureCount() - 1 << "): ";
    cin >> index;

    if (index < 0 || index >= m_creaturehandler->getCreatureCount())
    {
        cout << "Invalid creature index!" << endl;
        return;
    }

    Creature* creature = m_creaturehandler->getCreature(index);
    if (!creature)
    {
        cout << "Creature not found!" << endl;
        return;
    }

    int damage = m_character->attack();
    creature->takeDamage(damage);
    cout << "You attacked " << creature->getName() << " for " << damage << " damage!\n";

    if (!creature->isAlive())
    {
        cout << creature->getName() << " has been defeated!\n";
        m_creaturehandler->removeCreature(creature->getName());
    }
}
