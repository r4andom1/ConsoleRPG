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