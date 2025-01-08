#include "LocationOptions.h"

LocationOptions::LocationOptions(CharacterCreator& character, Inventory& inventory)
    : m_character(&character)
    , m_inventory(&inventory)
    , m_combatoptions(make_unique<CombatOptions>(character, inventory))
{
}

void LocationOptions::startChurchLocation()
{
    bool quitMenu = false;
    while (!quitMenu)
    {
        displayChurchOptions();
        char choice = UtilityFunctions::userChoice();

        if (choice == '1') 
        {
            m_character->takeDamage(6); // test
            m_character->heal(5); // test
            
        }
        else if (choice == '2') 
        {
        }
        else if (choice == '3') 
        {
            cout << m_character->toString() << endl;
        }
        else if (choice == '4') 
        {
        }
        else if (choice == '5')
        {
        }
        else if (choice == 'q') 
        {
            cout << "Exiting...\n";
            quitMenu = true;
        }
        else 
        {
            cout << "Invalid choice! Try again.\n";
        }
        if (!quitMenu)
        {
            UtilityFunctions::confirmToContinue();
        }
    }
}

void LocationOptions::startCaveLocation()
{
    bool quitMenu = false;
    while (!quitMenu)
    {
        displayCaveOptions();
        char choice = UtilityFunctions::userChoice();

        if (choice == '1')
        {
            m_combatoptions->startCombatLoop();
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
        }
        else if (choice == '5')
        {
        }
        else if (choice == 'q')
        {
            cout << "Exiting...\n";
            quitMenu = true;
        }
        else
        {
            cout << "Invalid choice! Try again.\n";
        }
        if (!quitMenu)
        {
            UtilityFunctions::confirmToContinue();
        }
    }
}


void LocationOptions::displayChurchOptions() const
{
    cout << "1. Enter Church and talk to priest" << endl;
    cout << "2. Open Inventory" << endl;
    cout << "3. Check Stats" << endl;
    cout << "q. Exit Church location" << endl;

}

void LocationOptions::displayCaveOptions() const
{
    cout << "1. Enter Cave to fight the goblins" << endl;
    cout << "2. Open Inventory" << endl;
    cout << "3. Check Stats" << endl;
    cout << "q. Exit Cave location" << endl;

}
