#include "Game.h"
#include "StartMenu.h"
#include <iostream>
using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	StartMenu menu;
	menu.start();
}

// TODO: Implementera combat i Cave area. 
// 
// TODO: Fixa inventory så att när vi har dödat enemies så droppar de 1 health pot och om vi har tid, en damage-buff scroll.
// Lägg även till så att healern faktiskt kan bli healad om de använder en health pot
// 
// TODO: Fixa en creature handler som vi har gjort tidigare i kursen. Man ska kunna lägga till, ta väck, sätta deras hp etc.
// Creature handlern måste ha creatures i en array så vi får igenom det kravet.
// 
// TODO: Ta väck alla onödiga kommentarer (Dock ej docstrings och förklaringar för funktioner!!)