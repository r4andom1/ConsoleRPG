#include "Item.h"

using namespace std;

Item::Item(const string& itemName, const string& itemDescription)
    : name(itemName)
    , description(itemDescription)
{
}

string Item::toString() const {
    return name + " | " + description;
}

Item Item::fromString(const string& itemData) {
    size_t delimiterPos = itemData.find('|');
    string itemName = itemData.substr(0, delimiterPos);
    string itemDescription = itemData.substr(delimiterPos + 1);
    return Item(itemName, itemDescription);
}
