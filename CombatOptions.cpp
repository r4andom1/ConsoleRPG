#include "CombatOptions.h"
#include "Goblin.h"

CombatOptions::CombatOptions(CreatureHandler& creatureHandler, CharacterCreator& character, Inventory& inventory)
    : m_creatureHandler(creatureHandler), m_character(&character), m_inventory(&inventory)
{
}

CombatOptions::~CombatOptions()
{
    m_creatureHandler.removeAllCreatures();
}


void CombatOptions::startCombatLoop()
{
    bool isRunning = true;

    m_creatureHandler.addCreature(new Goblin("Goblin Warrior", 1, 6, 6, 2, true));
    m_creatureHandler.addCreature(new Goblin("Goblin Archer", 1, 5, 5, 2, true));

    while (isRunning)
    {
        cout << "\n--- Combat Menu ---\n";

        cout << "\nRemaining Creatures HP:\n";
        m_creatureHandler.listCreatures();  

        cout << "\nYour HP: " << m_character->getCurrentHP() << endl;

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
            m_inventory->manageInventory();
            m_inventory->saveToFile();
        }
        else if (choice == '3')
        {
            cout << m_character->toString() << endl;
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

        if (m_character->getCurrentHP() <= 0)
        {
            cout << "You have been defeated!\n";
            break;
        }

   
        for (int i = 0; i < m_creatureHandler.getCreatureCount(); ++i)
        {
            Creature* creature = m_creatureHandler.getCreature(i);
            if (creature && creature->isAlive())
            {
                int damage = creature->basicAttack();
                m_character->takeDamage(damage);
            }
        }
        if (m_character->getCurrentHP() <= 0)
        {
            cout << "You have been defeated!\n";
            isRunning = false;
        }
           
            UtilityFunctions::confirmToContinue();

    }
    m_creatureHandler.removeAllCreatures();
}


void CombatOptions::attackCreature()
{
    int creatureCounter = m_creatureHandler.getCreatureCount();
    if (creatureCounter == 0)
    {
        cout << "No creatures to attack!" << endl;
        return;
    }

    cout << "Choose a creature to attack:\n";
    for (int i = 0; i < creatureCounter; i++) 
        {
            Creature* creature = m_creatureHandler.getCreature(i);
            if (creature)
            {
                cout << i + 1 << ". " << creature->getName() << " | HP: " << creature->getCurrentHealth() << "\n";
            }
        }

    int choice;
    cout << "Enter the creature you want to attack 1-" << creatureCounter<< ": ";
    cin >> choice;

    if (choice < 1 || choice > creatureCounter)
    {
        cout << "Invalid choice!" << endl;
        return;
    }

    Creature* creature = m_creatureHandler.getCreature(choice - 1);
    if (creature == nullptr)
    {
        cout << "Creature not found!" << endl;
        return;
    }

    int damage = m_character->attack();
    creature->takeDamage(damage);

    if (!creature->isAlive())
    {
        cout << creature->getName() << " has been defeated!\n";
        m_creatureHandler.removeCreature(creature->getName());
    }
}

