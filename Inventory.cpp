#include "Inventory.h"
#include <fstream>
#include <iostream>

using namespace std;

Inventory::Inventory(CharacterCreator& character, const string& file)
    : fileName(file) 
    , m_character(&character)
{
    loadFromFile();
}

void Inventory::addItem(const Item& item) 
{
    items.push_back(item);
    saveToFile();
}

bool Inventory::dropItem(const string& itemName)
{
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->getName() == itemName) 
        {
            items.erase(it);
            saveToFile();
            return true;
        }
    }
    return false;
}

void Inventory::displayInventory() const 
{
    if (items.empty()) 
    {
        cout << "Your inventory is empty.\n";
        return;
    }

    cout << "Your inventory contains:\n";
    for (const auto& item : items) 
    {
        cout << "- " << item.getName() << " | " << item.getDescription() << "\n";
    }
}

void Inventory::saveToFile() const 
{
    ofstream file(fileName);
    if (file.is_open()) 
    {
        for (const auto& item : items) {
            file << item.toString() << "\n";
        }
        file.close();
    }
    else {
        cerr << "Unable to save inventory to file.\n";
    }
}

void Inventory::loadFromFile() 
{
    items.clear();
    ifstream file(fileName);
    if (file.is_open()) 
    {
        string line;
        while (getline(file, line)) {
            if (!line.empty()) {
                items.push_back(Item::fromString(line));
            }
        }
        file.close();
    }
    else {
        cerr << "Unable to load inventory from file. Starting with an empty inventory.\n";
    }
}

void Inventory::createHealingPotion() 
{
    Item healingPotion("Healing Potion", "Restores health when used.");
    addItem(healingPotion);
    cout << "Healing Potion has been added to your inventory." << endl;
}

void Inventory::useHealingPotion() 
{
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->getName() == "Healing Potion") 
        {
            int healedAmount = 5;
            m_character->heal(healedAmount);

            items.erase(it);
            saveToFile();

            cout << "You used a Healing Potion and restored " << healedAmount << " HP!" << endl;
            return;
        }
    }
    cout << "You do not have a Healing Potion in your inventory." << endl;
}

void Inventory::manageInventory() {
    bool isRunning = true;

    while (isRunning) {
        UtilityFunctions::clearConsole();
        cout << "\n--- Inventory Menu ---\n";
        cout << "1. View Inventory\n";
        cout << "2. Add Item\n";
        cout << "3. Drop Item\n";
        cout << "4. Use Item\n";
        cout << "5. Add HP Potion\n";
        cout << "q. Exit Inventory\n";

        char choice = UtilityFunctions::userChoice(); // Get user input

        if (choice == 'q') {
            saveToFile();
            cout << "Inventory saved. Exiting...\n";
            isRunning = false;
        }
        else if (choice == '1') {
            displayInventory();
        }
        else if (choice == '2') {
            string name, description;
            cout << "Enter item name: ";
            getline(cin, name);
            cout << "Enter item description: ";
            getline(cin, description);
            addItem(Item(name, description));
        }
        else if (choice == '3') {
            displayInventory();
            string name{};
            cout << "Enter item name to drop: ";
            getline(cin, name);
            if (dropItem(name)) {
                cout << name << " dropped from inventory.\n";
            }
            else {
                cout << name << " not found in inventory.\n";
            }
        }
        else if (choice == '4') {
            displayInventory();
            cout << "Enter item name to use: ";
            string name;
            getline(cin, name);

            if (name == "Healing Potion") {
                useHealingPotion();
            }
            else {
                cout << "This item cannot be used." << endl;
            }
        }
        else if (choice == '5') {
            createHealingPotion();
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
        if (isRunning)
        {
            UtilityFunctions::confirmToContinue();
        }
    }
}