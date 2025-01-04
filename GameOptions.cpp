#include "GameOptions.h"
#include "Church.h"
#include "Cave.h"
#include <iostream>
#include <string>

using namespace std;

GameOptions::GameOptions()
{
    // Available locations
    locations.push_back(make_unique<Church>());
    locations.push_back(make_unique<Cave>());

    // Default location
    currentLocation = make_unique<Church>();
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

void GameOptions::showStatistiks()
{
    cout << "Checking stats...\n";
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
    while (true) {
        cout << "\nGame Menu:\n";
        cout << "1. Travel\n";
        cout << "2. Open Inventory\n";
        cout << "3. Check Stats\n";
        cout << "4. Show Current Location\n";
        cout << "q. Exit\n";
        cout << "Enter your choice: ";

        string choice;
        cin >> choice;

        if (choice == "1") {
            travel();
        }
        else if (choice == "2") {
            inventory();
        }
        else if (choice == "3") {
            showStatistiks();
        }
        else if (choice == "4") {
            showCurrentLocation();
        }
        else if (choice == "q") {
            cout << "Exiting game...\n";
            break;
        }
        else {
            cout << "Invalid choice! Try again.\n";
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
        cout << "4. Use Item\n";
        cout << "5. Add HP Potion\n";
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
        else if (choice == '4') {
            cout << "Enter item name to use: ";
            string name;
            getline(cin, name);

            if (name == "Healing Potion") {
                inventory.useHealingPotion();
            }
            else {
                cout << "This item cannot be used." << endl;
            }
        }
        else if (choice == '5') {
            inventory.createHealingPotion();
        }

        else {
            cout << "Invalid choice. Try again.\n";
        }
    }
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