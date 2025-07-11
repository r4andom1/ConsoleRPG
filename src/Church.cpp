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
    return "Church of Radiant Dawn";
}

string Church::areaDescription() const
{
    return "You are standing outside the Church.";
}
