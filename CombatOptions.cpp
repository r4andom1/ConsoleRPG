#include "CombatOptions.h"

CombatOptions::CombatOptions(CharacterCreator& character, Inventory& inventory)
	: m_character(&character)
    , m_inventory(&inventory)
{
}

void CombatOptions::startCombatLoop()
{
    bool isRunning = true;

    while (isRunning)
    {
        UtilityFunctions::clearConsole();
        char choice = UtilityFunctions::userChoice();

        cout << "\n--- Combat Menu ---\n";
        cout << "1. Attack" << endl;
        cout << "2. View Inventory" << endl;
        cout << "3. View Stats" << endl;
        cout << "q. exit" << endl;

        if (choice == '1')
        {
            m_character->takeDamage(5); // test
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

