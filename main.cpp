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
// TODO: Fixa inventory s� att n�r vi har d�dat enemies s� droppar de 1 health pot och om vi har tid, en damage-buff scroll.
// L�gg �ven till s� att healern faktiskt kan bli healad om de anv�nder en health pot
// 
// TODO: Fixa en creature handler som vi har gjort tidigare i kursen. Man ska kunna l�gga till, ta v�ck, s�tta deras hp etc.
// Creature handlern m�ste ha creatures i en array s� vi f�r igenom det kravet.
// 
// TODO: Fixa Creature klass som en abstract klass som sedan Goblin �rver av. 
// Alla creatures kommer ha HP, damage, en bool om de lever etc. 
// 
// FR�GA BETTY: M�ste vi ta v�ck alla kommentarer? Vill spara de som f�rklarar vad vissa funktioner g�r.