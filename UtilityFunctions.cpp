#include "UtilityFunctions.h"

/* Pauses console output for nr of seconds */
void UtilityFunctions::clearConsole()
{
	system("cls");
}

/* Takes user choice as input, cleans up input buffer and returns choice */
char UtilityFunctions::userChoice()
{
    cout << "\nEnter your choice : ";
    char choice{};
    cin >> choice;
    if (!cin)
    {
        cin.clear();
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    clearConsole(); // Added this
    return choice;
}

/* Gives user a confirmation before continuing to another choice in menu */
void UtilityFunctions::confirmToContinue()
{
    string confirm;
    cout << "\nPress enter to continue.." << endl;
    //cin.ignore(numeric_limits<streamsize>::max(), '\n'); // messes with input buffer? Maybe have it after getline
    getline(cin, confirm);
    clearConsole();
}

/* Pauses console output for nr of seconds */
void UtilityFunctions::sleepTimer(int seconds)
{
    this_thread::sleep_for(chrono::seconds(seconds));
}
