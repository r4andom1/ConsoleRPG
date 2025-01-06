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
    /*return "Nestled deep within the jagged cliffs, Goblin Hollow is a chaotic, "
        "yet vibrant cave system where mischievous goblins make their home. "
        "The entrance is hidden behind thick vines, but once inside, "
        "the winding tunnels are lined with crude wooden structures and glowing mushrooms. "
        "The goblins live in constant turmoil, crafting odd contraptions and scavenging treasures. "
        "Stale scents of food and smoldering fires fill the air, "
        "and the constant clatter of goblin chatter echoes through the tunnels. "
        "It's a place of wild energy, where adventurers might find both dangerous "
        "traps and unexpected allies among the creatures of the cave.";*/

    return "You are standing outside the cave";
}
