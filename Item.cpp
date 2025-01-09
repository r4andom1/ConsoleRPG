#include "Item.h"

using namespace std;

Item::Item(const string& itemName, const string& itemDescription)
    : name(itemName)
    , description(itemDescription)
{
}

string Item::toString() const {
    return name + "|" + description;
}

Item Item::fromString(const string& itemData) {
    size_t separatorPos = itemData.find('|');
    string itemName = itemData.substr(0, separatorPos);
    string itemDescription = itemData.substr(separatorPos + 1);
    return Item(itemName, itemDescription);
}
