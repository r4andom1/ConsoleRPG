#pragma once

#include <vector>
#include <string>
#include "Item.h"

using namespace std;

class Inventory {
private:
    vector<Item> items;
    string fileName;

public:
    Inventory(const string& file = "inventory.txt");

    // Inventory operations
    void addItem(const Item& item);
    bool removeItem(const string& itemName);
    void displayInventory() const;

    // File operations
    void saveToFile() const;
    void loadFromFile();
};
