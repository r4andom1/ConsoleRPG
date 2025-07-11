#include "Cave.h"
#include <iostream>

void Cave::drawImage() const
{
    cout << "               _____\n";
    cout << "            .-'     `-.\n";
    cout << "         .-'           `-.\n";
    cout << "       .'   .-'`'-.       `.\n";
    cout << "     .'   .'       `.        `.\n";
    cout << "    /    /           \\         \\\n";
    cout << "   /    /             \\         \\\n";
    cout << "  /    /               \\         \\\n";
    cout << " /    /                 \\         \\\n";
    cout << "|     |                 |          |\n";
    cout << "|     |                 |          |\n";
    cout << endl;
}

string Cave::getName() const
{
    return "Goblin Hollow";
}

string Cave::areaDescription() const
{
    return "You are standing outside the cave";
}
