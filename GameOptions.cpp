#include "GameOptions.h"
#include "Church.h"
#include "Cave.h"
#include "Inventory.h"
#include <iostream>
#include <string>

using namespace std;

GameOptions::GameOptions(CharacterCreator& character)
    : m_character(&character)
    , m_optionsRunning(false)
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


void GameOptions::inventory()
{
    cout << "Opening inventory...\n";
    Inventory inventory("inventory.txt");
    manageInventory(inventory);
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
        displayGameOptions();

        char choice = userChoice();

        if (choice == '1') {
            travel();
        }
        else if (choice == '2') {
            inventory();
        }
        else if (choice == '3') {
            showCharacterStats();
        }
        else if (choice == '4') {
            showCurrentLocation();
        }
        else if (choice == '5') // testing combat feature
        {
            m_character->attack();
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
            string confirm;
            cout << "\nPress enter to continue.." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, confirm);
            clearConsole();
        }
    }
}

void GameOptions::manageInventory(Inventory& inventory) {
    bool isRunning = true;

    while (isRunning) {
        cout << "\n--- Inventory Menu ---\n";
        cout << "1. View Inventory\n";
        cout << "2. Add Item\n";
        cout << "3. Drop Item\n";
        cout << "q. Exit Inventory\n";

        char choice = userChoice(); // Get user input

        if (choice == 'q') {
            inventory.saveToFile();
            cout << "Inventory saved. Exiting...\n";
            isRunning = false;
        }
        else if (choice == '1') {
            inventory.displayInventory();
        }
        else if (choice == '2') {
            string name, description;
            cout << "Enter item name: ";
            getline(cin, name);
            cout << "Enter item description: ";
            getline(cin, description);
            inventory.addItem(Item(name, description));
        }
        else if (choice == '3') {
            string name;
            cout << "Enter item name to drop: ";
            getline(cin, name);
            if (inventory.dropItem(name)) {
                cout << name << " dropped from inventory.\n";
            }
            else {
                cout << name << " not found in inventory.\n";
            }
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }
}

void GameOptions::displayGameOptions() const
{
    cout << "\nGame Menu:\n";
    cout << "1. Travel\n";
    cout << "2. Open Inventory\n";
    cout << "3. Check Stats\n";
    cout << "4. Show Current Location\n";
    cout << "5. Combat testing \n"; // testing combat feature
    cout << "q. Exit to Main Menu\n";
    cout << "Enter your choice: ";
}

/* Clears console window */
void GameOptions::clearConsole()
{
    system("cls");
}

char GameOptions::userChoice() const
{
    cout << "Enter your choice : " << endl;
    char choice{};
    cin >> choice;
    if (!cin)
    {
        cin.clear();
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}