#include "CombatOptions.h"

CombatOptions::CombatOptions(CharacterCreator* character, Inventory* inventory)
	: m_character(character), m_inventory(inventory)
{
}

void CombatOptions::StartCombatLoop()
{
    bool isRunning = true;

    while (isRunning)
    {
        char choice = UtilityFunctions::userChoice();

        cout << "\n--- Combat Menu ---\n";
        cout << "1. Attack" << endl;
        cout << "2. View Inventory" << endl;
        cout << "3. View Stats" << endl;

        if (choice == '1')
        {
        }
        else if (choice == '2')
        {
            m_inventory->displayInventory();
        }
        else if (choice == '3')
        {
            cout << m_character->toString() << endl;
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