#include "Church.h"
#include <iostream>

void Church::drawImage() const
{
    cout << "        .\n"; 
    cout << "      .' '.\n";
    cout << "     .'  | `.\n";
    cout << "   .'    |   `.\n";
    cout << "  .`---..|..---'.\n";
    cout << "   ||   |=|   ||\n";
    cout << "   ||_.-'|`-._||\n";
    cout << "   ||`-._|_.-'||\n";
    cout << " __||   |=|   ||_\n";
    cout << "'._ `-. |=| .-' _`\n";
    cout << "   `-._|=|_.-'  \\\n";
    cout << "       |=|       \\\n";
    cout << "       |_|        |\n";
    cout << "       | |        |\n";
    cout << "       |_|        |\n";
    cout << "       |_|        |\n";
    cout << "                  '\n";
    cout << endl;
}

string Church::getName() const
{
    return "Churtch of Radiant Dawn";
}

string Church::areaDescription() const
{
    return "A beacon of light in a troubled land, this churtch radiates an aura of warmth and healing. "
        "Pilgrims travel from distant realms to seek blessings from its revered High Priest, "
        "though dark forces conspire to shroud its holy light.";
}
