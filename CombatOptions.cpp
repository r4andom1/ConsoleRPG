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

    while (isRunning)
    {
        UtilityFunctions::clearConsole();
        cout << "\n--- Combat Menu ---\n";
        cout << "1. Attack" << endl;
        cout << "2. View Inventory" << endl;
        cout << "3. View Stats" << endl;
        cout << "q. exit" << endl;
        char choice = UtilityFunctions::userChoice();

        if (choice == '1')
        {
            m_locationOptions->setCaveQuestCompleted(true); // test
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

