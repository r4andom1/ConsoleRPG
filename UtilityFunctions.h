#pragma once
#include <iostream>
#include <thread> // sleep functionality
#include <chrono> // sleep functionality
#include <string>

using namespace std;

namespace UtilityFunctions
{
	void clearConsole();
	char userChoice();
	void confirmToContinue();
	void sleepTimer(int seconds);
}

