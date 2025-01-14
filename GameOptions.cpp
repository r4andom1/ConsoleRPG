#include "GameOptions.h"
#include "Church.h"
#include "Cave.h"
#include "Inventory.h"
#include <iostream>
#include <string>

using namespace std;

GameOptions::GameOptions(CharacterCreator& character)
    : m_character(&character)
    , m_inventory(make_unique<Inventory>(character, "inventory.txt"))
    , m_locationOptions(*m_character, *m_inventory)
    , m_optionsRunning(true)
    , m_firstPlaythrough(true)
{
    // Available locations
    locations.push_back(make_unique<Church>());
    locations.push_back(make_unique<Cave>());

    // Default location
    currentLocation = make_unique<Church>();
}

GameOptions::~GameOptions()
{
}

void GameOptions::travel()
{
    UtilityFunctions::clearConsole();
    cout << "Where would you like to travel?\n";
    for (size_t i = 0; i < locations.size(); ++i) 
    {
        cout << i + 1 << ". " << locations[i]->getName() << "\n";
    }
    int choice;
    cin >> choice;

    if (choice > 0 && choice <= static_cast<int>(locations.size())) 
    {
        currentLocation = locations[choice - 1];
        cout << "You traveled to " << currentLocation->getName() << "!\n";
        currentLocation->drawImage();
        cout << currentLocation->areaDescription() << endl;
    }
    else 
    {
        cout << "Invalid choice!\n";
    }
}

void GameOptions::showCharacterStats()
{
    UtilityFunctions::clearConsole();
    cout << "Checking stats...\n";
    cout << m_character->toString() << endl;
    cout << m_character->drawPlayer() << endl;
}

void GameOptions::showCurrentLocation() const // Maybe Remove?
{
    if (currentLocation) {
        cout << "Current Location: " << currentLocation->getName() << "\n";
        currentLocation->drawImage();
        currentLocation->areaDescription();
    }
    else 
    {
        cout << "You are nowhere!\n";
    }
}

void GameOptions::gameMenuStarter()
{
    setIsRunning(true);
    while (isRunning()) 
    {
        UtilityFunctions::clearConsole();
        startingAreaDescription();
        setFirstPlaythrough(false);
        currentLocation->drawImage();
        displayGameOptions();

        char choice = UtilityFunctions::userChoice();

        if (choice == '1') 
        {
            travel();
        }
        else if (choice == '2') {
            cout << "Opening inventory...\n";
            manageInventory(*m_inventory);
        }
        else if (choice == '3') 
        {
            showCharacterStats();
        }
        else if (choice == '4')
        {
            if (currentLocation->getName() == "Goblin Hollow")
            {
                m_locationOptions.startCaveLocation();
            }
            else if (currentLocation->getName() == "Church of Radiant Dawn")
            {
                m_locationOptions.startChurchLocation();
            }
        }
        else if (choice == 'q') 
        {
            cout << "Exiting game...\n";
            setIsRunning(false);
        }
        else 
        {
            cout << "Invalid choice! Try again.\n";
        }
        if (isRunning())
        {
            UtilityFunctions::confirmToContinue();
        }
    }
}

void GameOptions::manageInventory(Inventory& inventory)
{
    inventory.manageInventory();
}

void GameOptions::displayGameOptions() const
{
    cout << "\nGame Menu:\n";
    cout << "1) Travel\n";
    cout << "2) Open Inventory\n";
    cout << "3) Check Stats\n";
    cout << "4) Explore your current location \n"; // testing combat feature
    cout << "q) Exit to Main Menu\n";
}

void GameOptions::startingAreaDescription() const
{
    if (getFirstPlaythrough())
    {
        cout << "You awake at the foot of a tree,\njust outside a small village.\n";
        cout << "\nKnowing this is the last known location of your kidnapped brother,";
        cout << "\nyou stand up on your feet and continue your search.";
        cout << "\n";
        cout << "\nYou scan your surroundings and see a church in disrepair, what would you like to do next?\n";
        UtilityFunctions::confirmToContinue();
    } 
}
