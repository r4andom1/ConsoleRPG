#include "CombatOptions.h"

CombatOptions::CombatOptions(CharacterCreator& character, Inventory& inventory, LocationOptions& locationOptions)
	: m_character(&character)
    , m_inventory(&inventory)
    , m_locationOptions(&locationOptions)
{
}

void CombatOptions::startCombatLoop()
{
    bool isRunning = true;

    CreatureHandler creatureHandler;
    creatureHandler.addGoblin("Goblin", 2, 7, 7, 1); // test
    creatureHandler.addGoblin("Goblin", 2, 5, 5, 1); // test

    while (isRunning)
    {
        if (creatureHandler.getCreatureCount() == 0)
        {
            cout << "You have defeated the goblins!" << endl;
            m_locationOptions->setCaveQuestCompleted(true);
            break;
        }
        UtilityFunctions::clearConsole();

        creatureHandler.displayAllCreatures();
        displayCombatOptions();
        char choice = UtilityFunctions::userChoice();

        if (choice == '1')
        {
            cout << "Choose a creature to attack:\n\n";
            creatureHandler.displayAllCreatures();
                
            int index{};
            cout << "Enter the creature index (1-" << creatureHandler.getCreatureCount() << "): ";
            cin >> index;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (index < 1 || index > creatureHandler.getCreatureCount())
            {
                cout << "Invalid creature index!" << endl;
                return;
            }
            Creature* creatureTargeted = creatureHandler.getCreature(index - 1);
            int playerDamage = m_character->attack();
            cout << endl;

            creatureTargeted->takeDamage(playerDamage);

            if (!creatureTargeted->isAlive())
            {
                cout << creatureTargeted->getName() << " has been defeated!\n";
                creatureHandler.removeCreature(index - 1);
            }
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
            cout << m_character->drawPlayer() << endl;
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

//void CombatOptions::startFightWithGoblins()
//{
//    CreatureHandler creatureHandler;
//    creatureHandler.addGoblin("Goblin Warrior", 2, 7, 7, 1); // test
//    creatureHandler.addGoblin("Goblin Archer", 2, 5, 5, 1); // test
//    //creatureHandler.removeCreature(1); // test
//    if (creatureHandler.getCreatureCount() == 0)
//    {
//        cout << "No creatures to attack!" << endl;
//        return;
//    }
//
//    cout << "Choose a creature to attack:\n\n";
//    creatureHandler.displayAllCreatures();
//
//    int index;
//    cout << "Enter the creature index (1-" << creatureHandler.getCreatureCount() << "): ";
//    cin >> index;
//
//    if (index < 0 || index >= creatureHandler.getCreatureCount())
//    {
//        cout << "Invalid creature index!" << endl;
//        return;
//    }
//    Creature* creatureTargeted = creatureHandler.getCreature(index - 1);
//    int playerDamage = m_character->attack();
//
//    if (creatureTargeted != nullptr)
//    {
//        creatureTargeted->takeDamage(playerDamage);
//        cout << "You attacked " << creatureTargeted->getName() << " for " << playerDamage << " damage!\n";
//
//        if (!creatureTargeted->isAlive())
//        {
//            cout << creatureTargeted->getName() << " has been defeated!\n";
//            creatureHandler.removeCreature(index);
//        }
//    }
//}

void CombatOptions::displayCombatOptions() const
{
    cout << "\n--- Combat Menu ---\n";
    cout << "1. Attack" << endl;
    cout << "2. View Inventory" << endl;
    cout << "3. View Stats" << endl;
    cout << "q. exit" << endl;
}

