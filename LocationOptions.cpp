#include "LocationOptions.h"

LocationOptions::LocationOptions(CharacterCreator& character, Inventory& inventory)
    : m_character(&character)
    , m_caveQuestCompleted(false)
    , m_firstEncounterWithPriest(true)
    , m_inventory(&inventory)
{
}

void LocationOptions::startChurchLocation()
{
    bool quitMenu = false;
    while (!quitMenu)
    {
        UtilityFunctions::clearConsole();
        drawChurch();
        displayChurchOptions();
        char choice = UtilityFunctions::userChoice();

        if (choice == '1') 
        {
            priestDialogueChoice();
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

void LocationOptions::priestDialogueChoice()
{
    bool quitMenu = false;
    while (!quitMenu)
    {
        UtilityFunctions::clearConsole();
        drawPriest();
        priestDialogueOptions();
        char choice = UtilityFunctions::userChoice();

        if (choice == '1')
        {
            if (!m_caveQuestCompleted)
            {
                if (m_firstEncounterWithPriest)
                {
                    drawPriest();
                    firstEncounterPriest();
                }
                else
                {
                    drawPriest();
                    cout << "What are you still doing here? I thought i asked you to take care of those goblins!" << endl;
                }
            }
            else // Done with cave quest
            {
                drawPriest();
                cout << "Thank you so much for helping out! Here is your reward: bla bla" << endl;
            }
        }
        else if (choice == '2')
        {
            drawPriest();
            cout << "The priest heals you to full health!" << endl;
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
    cout << "1) QUEST: The Goblin Problem" << endl;
    cout << "2) Heal to full health" << endl;
    cout << "q) Exit church" << endl;
}

void LocationOptions::startCaveLocation()
{
    bool quitMenu = false;
    while (!quitMenu)
    {
        UtilityFunctions::clearConsole();
        displayCaveOptions();
        char choice = UtilityFunctions::userChoice();

        if (choice == '1')
        {
            CombatOptions combatOptions(*m_character, *m_inventory, *this);
            combatOptions.startCombatLoop();
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
    cout << "1) Enter Church and talk to priest" << endl;
    cout << "2) Open Inventory" << endl;
    cout << "3) Check Stats" << endl;
    cout << "q) Exit Church location" << endl;
}

void LocationOptions::firstEncounterPriest()
{
    cout << "You enter the church and walk up to the priest." << endl;
    cout << "The priest is excited to see a adventurer and asks for help with the goblins that have been ravaging their church." << endl;
    cout << "He promises that there is a big reward waiting for you if you help out." << endl;
    setFirstEncounterWithPriest(false);
}

void LocationOptions::drawChurch() const
{
    cout << "        .\n";
    cout << "      .' '.\n";
    cout << "     .'  | `.\n";
    cout << "   .'    |   `.\n";
    cout << "  .`---..|..---'.\n";
    cout << "   ||   |=|   ||\n";
    cout << "   ||_.-'|`-._||\n";
    cout << "   ||`-._|_.-'||\n";
    cout << " __||   |=|   ||_\n";
    cout << "'._ `-. |=| .-' _`\n";
    cout << "   `-._|=|_.-'  \\\n";
    cout << "       |=|       \\\n";
    cout << "       |_|        |\n";
    cout << "       | |        |\n";
    cout << "       |_|        |\n";
    cout << "       |_|        |\n";
    cout << "                  '\n";
    cout << endl;
}

void LocationOptions::drawPriest() const
{
    cout << R"(
           .---.
         /` ___|`\
         |_/    \|
         (  -/-  )
          \_ - _/
         .-'|_|'-.
        /         \
       /     O     \
      / _____!_____ \
     /.-------------.\
     \|     ,;,     |/
      |     ;;;     |
      |  ;;;;;;;;;  |
      |   `';;;'`   |
      |     ;;;     |
      |     ;;;     |
      |     :::     |
      |     ';'     |
      |             |
     _| _  __   __ _|_
   _/ _  __  ___  __ _\_
 _/ __  ___  _ ___ __ _ \_
    )" << endl;
}

void LocationOptions::displayCaveOptions() const
{
    cout << "1) Enter Cave to fight the goblins" << endl;
    cout << "2) Open Inventory" << endl;
    cout << "3) Check Stats" << endl;
    cout << "q) Exit Cave location" << endl;
}
