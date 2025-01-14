#include "CombatOptions.h"
#include "Goblin.h"

CombatOptions::CombatOptions(CreatureHandler& creatureHandler, CharacterCreator& character, Inventory& inventory)
    : m_handler(&creatureHandler)
    , m_character(&character)
    , m_inventory(&inventory)
{
    m_handler->addCreature(new Goblin("Goblin Warrior", 3, 6, 6, 2));
    m_handler->addCreature(new Goblin("Goblin Archer", 4, 5, 5, 2));
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
            m_handler->listCreatures();
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
    if (m_handler->getCreatureCount() == 0)
    {
        cout << "No creatures to attack!" << endl;
        return;
    }

    cout << "Choose a creature to attack:\n";
    m_handler->listCreatures();

    int index;
    cout << "Enter the creature index (0-" << m_handler->getCreatureCount() - 1 << "): ";
    cin >> index;

    Creature* creature = m_handler->getCreature(index);
    if (creature)
    {
        int damage = m_character->attack();
        creature->takeDamage(damage);
        cout << "You attacked " << creature->getName() << " for " << damage << " damage!\n";

        if (!creature->isAlive())
        {
            cout << creature->getName() << " has been defeated!\n";
            m_handler->removeCreature(creature->getName());
        }
    }
    else
    {
        cout << "Invalid creature index!\n";
    }
}
