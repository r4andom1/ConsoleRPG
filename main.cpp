#include "Game.h"
#include "StartMenu.h"
#include <iostream>
using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	StartMenu menu;
	menu.start();

	return 0;
}

// TODO: Implementera combat i Cave area. 
// 
// 
// TODO: Fixa en creature handler som vi har gjort tidigare i kursen. Man ska kunna l�gga till, ta v�ck, s�tta deras hp etc.
// Creature handlern m�ste ha creatures i en array s� vi f�r igenom det kravet.
// 
// TODO: Ta v�ck alla on�diga kommentarer (Dock ej docstrings och f�rklaringar f�r funktioner!!)2
