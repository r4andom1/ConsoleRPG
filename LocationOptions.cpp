#include "LocationOptions.h"

LocationOptions::LocationOptions(CharacterCreator& character, Inventory& inventory)
    : m_character(&character)
    , m_caveQuestCompleted(false)
    , m_firstEncounterWithPriest(true)
{
}

void LocationOptions::startChurchLocation()
{
    bool quitMenu = false;
    while (!quitMenu)
    {
        UtilityFunctions::clearConsole();
        displayChurchOptions();
        char choice = UtilityFunctions::userChoice();

        if (choice == '1') 
        {
            priestDialogueChoice();
        }
        else if (choice == '2') 
        {
            Inventory inventory(*m_character, "inventory.txt");
            inventory.displayInventory(); // change to manage inventory
        }
        else if (choice == '3') 
        {
            cout << m_character->toString() << endl;
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
}

void LocationOptions::displayChurchOptions() const
{
    cout << "1) Enter Church and talk to priest" << endl;
    cout << "2) Open Inventory" << endl;
    cout << "3) Check Stats" << endl;
    cout << "q) Exit Church location" << endl;

}

void LocationOptions::priestDialogueChoice()
{
    bool quitMenu = false;
    while (!quitMenu)
    {
        UtilityFunctions::clearConsole();
        priestDialogueOptions();
        char choice = UtilityFunctions::userChoice();

        if (choice == '1')
        {
            if (!m_caveQuestCompleted)
            {
                if (m_firstEncounterWithPriest)
                {
                    firstEncounterPriest();
                }
                else
                {
                    cout << "What are you still doing here? I thought i asked you to take care of those goblins!" << endl;
                }
            }
            else
            {
                cout << "Thank you so much for helping out! Here is your reward: bla bla" << endl;
            }
        }
        else if (choice == '2')
        {
            cout << "The priest heals you to full health." << endl;
            int fullHealth = m_character->getMaxHP();
            m_character->heal(fullHealth);
        }
        else if (choice == 'q')
        {
            cout << "Exiting church...\n";
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

void LocationOptions::priestDialogueOptions() const
{
    cout << "1) QUEST: Slay the goblins" << endl;
    cout << "2) Heal yourself to full health" << endl;
    cout << "q) Exit Church location" << endl;
}

void LocationOptions::firstEncounterPriest()
{
    cout << "You enter the church and walk up to the priest." << endl;
    cout << "The priest is excited to see a adventurer and asks for help with their goblin problem that has ravaged their village." << endl;
    cout << "He promises that there is a big award waiting for you if you help out." << endl;
    setFirstEncounterWithPriest(false);
}
