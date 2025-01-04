#include "Inventory.h"
#include <fstream>
#include <iostream>

using namespace std;

Inventory::Inventory(const string& file)
    : fileName(file) {
    loadFromFile();
}

void Inventory::addItem(const Item& item) {
    items.push_back(item);
}

bool Inventory::dropItem(const string& itemName)
{
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->getName() == itemName) {
            items.erase(it);
            return true;
        }
    }
    return false;
}

void Inventory::displayInventory() const {
    if (items.empty()) {
        cout << "Your inventory is empty.\n";
        return;
    }

    cout << "Your inventory contains:\n";
    for (const auto& item : items) {
        cout << "- " << item.getName() << ": " << item.getDescription() << "\n";
    }
}

void Inventory::saveToFile() const {
    ofstream file(fileName);
    if (file.is_open()) {
        for (const auto& item : items) {
            file << item.toString() << "\n";
        }
        file.close();
    }
    else {
        cerr << "Unable to save inventory to file.\n";
    }
}

void Inventory::loadFromFile() {
    items.clear();
    ifstream file(fileName);
    if (file.is_open()) {
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

void Inventory::createHealingPotion() {
    Item healingPotion("Healing Potion", "Restores health when used.");
    items.push_back(healingPotion);

    cout << "Healing Potion has been added to your inventory." << endl;
}

void Inventory::useHealingPotion() {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->getName() == "Healing Potion") {
            //This shold be some ting outher than player. But player for now.
            int healedAmount = 5;
            //m_character.setHealt += healedAmount;

            items.erase(it);

            cout << "You used a Healing Potion and restored " << healedAmount << " HP!" << endl;
            return;
        }
    }
    cout << "You do not have a Healing Potion in your inventory." << endl;
}
