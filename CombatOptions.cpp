#include "CombatOptions.h"
#include "Goblin.h"

CombatOptions::CombatOptions(CreatureHandler& creatureHandler, CharacterCreator& character, Inventory& inventory)
    : m_creatureHandler(creatureHandler), m_character(character), m_inventory(inventory)
{
    if (&m_creatureHandler == nullptr) {
        cout << "CreatureHandler is not initialized properly!" << endl;
        return;
    }

    m_creatureHandler.addCreature(new Goblin("Goblin Warrior", 1, 6, 6, 2, true));
    m_creatureHandler.addCreature(new Goblin("Goblin Archer", 1, 5, 5, 2, true));
}


void CombatOptions::startCombatLoop()
{
    bool isRunning = true;

    while (isRunning)
    {
        cout << "\n--- Combat Menu ---\n";

        cout << "\nRemaining Creatures HP:\n";
        m_creatureHandler.listCreatures();  

        cout << "\n1. Attack\n";
        cout << "2. View Inventory\n";
        cout << "3. View Stats\n";
        cout << "4. View Remaining Creatures\n";
        cout << "q. Exit\n";

        char choice = UtilityFunctions::userChoice();

        if (choice == '1')
        {
            attackCreature();
        }
        else if (choice == '2')
        {
            cout << "Opening inventory...\n";
            m_inventory.manageInventory();
            m_inventory.saveToFile();
        }
        else if (choice == '3')
        {
            cout << m_character.toString() << endl;
        }
        else if (choice == '4')
        {
            m_creatureHandler.listCreatures();
        }
        else if (choice == 'q')
        {
            isRunning = false;
        }
        else
        {
            cout << "Invalid choice! Try again.\n";
        }

        if (m_character.getCurrentHP() <= 0)
        {
            cout << "You have been defeated!\n";
            cout << "Returning to the main menu...\n";
            isRunning = false;
        }

        if (isRunning)
        {
            for (int i = 0; i < m_creatureHandler.getCreatureCount(); ++i)
            {
                Creature* creature = m_creatureHandler.getCreature(i);
                if (creature && creature->isAlive())
                {
                    int damage = creature->basicAttack();
                    m_character.takeDamage(damage);
                    cout << "The " << creature->getName() << " attacks you for " << damage << " damage!" << endl;
                }
            }

            if (m_character.getCurrentHP() <= 0)
            {
                cout << "You have been defeated!\n";
                cout << "Returning to the main menu...\n";
                isRunning = false;
            }

            UtilityFunctions::confirmToContinue();
        }
    }
}


void CombatOptions::attackCreature()
{
    if (m_creatureHandler.getCreatureCount() == 0)
    {
        cout << "No creatures to attack!" << endl;
        return;
    }

    cout << "Choose a creature to attack:\n";
    m_creatureHandler.listCreatures();

    int index;
    cout << "Enter the creature index (0-" << m_creatureHandler.getCreatureCount() - 1 << "): ";
    cin >> index;

    if (index < 0 || index >= m_creatureHandler.getCreatureCount())
    {
        cout << "Invalid creature index!" << endl;
        return;
    }

    Creature* creature = m_creatureHandler.getCreature(index);
    if (creature == nullptr)
    {
        cout << "Creature not found!" << endl;
        return;
    }

    int damage = m_character.attack();
    creature->takeDamage(damage);
    cout << "You attacked " << creature->getName() << " for " << damage << " damage!\n";

    if (!creature->isAlive())
    {
        cout << creature->getName() << " has been defeated!\n";
        m_creatureHandler.removeCreature(creature->getName());
    }
}

