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
    , m_optionsRunning(true)
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
    cout << "Where would you like to travel?\n";
    for (size_t i = 0; i < locations.size(); ++i) {
        cout << i + 1 << ". " << locations[i]->getName() << "\n";
    }
    int choice;
    cin >> choice;

    if (choice > 0 && choice <= static_cast<int>(locations.size())) {
        currentLocation = locations[choice - 1];
        cout << "You traveled to " << currentLocation->getName() << "!\n";
        currentLocation->drawImage();
        cout << currentLocation->areaDescription() << endl;
    }
    else {
        cout << "Invalid choice!\n";
    }
}

void GameOptions::showCharacterStats()
{
    cout << "Checking stats...\n";
    cout << m_character->toString() << endl;
}

void GameOptions::showCurrentLocation() const
{
    if (currentLocation) {
        cout << "Current Location: " << currentLocation->getName() << "\n";
        currentLocation->drawImage();
        currentLocation->areaDescription();
    }
    else {
        cout << "You are nowhere!\n";
    }
}

void GameOptions::gameMenuStarter()
{
    setIsRunning(true);
    while (isRunning()) 
    {
        currentLocation->drawImage();
        cout << currentLocation->getName() << endl;
        displayGameOptions();

        char choice = UtilityFunctions::userChoice();

        if (choice == '1') {
            travel();
        }
        else if (choice == '2') {
            cout << "Opening inventory...\n";
            manageInventory(*m_inventory);
        }
        else if (choice == '3') {
            showCharacterStats();
        }
        else if (choice == '4') {
            showCurrentLocation();
        }
        else if (choice == '5') // testing exploration feature
        {
            Inventory inventory(*m_character, "inventory.txt");
            LocationOptions locationOptions(*m_character, *m_inventory);
            if (currentLocation->getName() == "Goblin Hollow")
            {
                // Do combat related stuff
                locationOptions.startCaveLocation();

            }
            else if (currentLocation->getName() == "Church of Radiant Dawn")
            {
                locationOptions.startChurchLocation();
            }
        }
        else if (choice == 'q') {
            cout << "Exiting game...\n";
            setIsRunning(false);
        }
        else {
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
    cout << "4) Show Current Location\n";
    cout << "5) Explore your current location \n"; // testing combat feature
    cout << "q) Exit to Main Menu\n";
}