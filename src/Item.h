#pragma once
#include <string>

using namespace std;


class Item {
private:
    string name;
    string description;

public:
    Item(const string& itemName = "", const string& itemDescription = "");

    // Member Variables
    string toString() const;
    static Item fromString(const string& itemData);

    // Getters and setters
    string getName() const { return name; }
    string getDescription() const { return description; }
    void setName(const string& itemName) { this->name = name; }
    void setDescription(const string& itemDescription) { this->name = name; }


};

