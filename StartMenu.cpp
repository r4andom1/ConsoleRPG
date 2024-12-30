#include "StartMenu.h"

StartMenu::StartMenu()
	: m_startMenu(false)
	, m_startGame(false)
	, m_character(nullptr)
{
}

StartMenu::~StartMenu()
{
	delete m_character;
}
/* Display options, create character etc. */
void StartMenu::start()
{
	setStartMenu(true);
	while (isRunning())
	{
		clearConsole();
		displayChoices();
		menuChoice(userChoice());
	}
}

void StartMenu::displayChoices() const
{
	cout << "Welcome to ConsoleRPG!" << endl;
	cout << endl;
	cout << "1) Start Game" << endl;
	cout << "2) Create Character" << endl;
	cout << "3) View your current character" << endl;
	cout << "4) Check inventory from last session" << endl;
	cout << "\nq) Exit Game" << endl;
}

char StartMenu::userChoice() const
{
	cout << "Enter your choice : " << endl;
	char choice{};
	cin >> choice;
	if (!cin)
	{
		cin.clear();
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return choice;
}

void StartMenu::menuChoice(char choice)
{
	if (choice == 'q')
	{
		// Exit Game 
		cout << "Exiting game.." << endl;
		setStartMenu(false);
	}
	else if (choice == '1')
	{
		// Create game object and start game here!
		if (m_character != nullptr)
		{
			//setStartMenu(false);
			//setStartGame(true);
			Game game(*m_character);
			game.run();
		}
		else
		{
			cout << "Create a character before starting the game!" << endl;
		}
	}
	else if (choice == '2')
	{
		cout << "Starting character creation.. " << endl;
		if (m_character == nullptr)
		{
			m_character = new CharacterCreator();
			m_character->createCharacter();
		}
	}
	else if (choice == '3')
	{
		if (m_character != nullptr)
		{
			cout << m_character->toString() << endl;
		}
		else
		{
			cout << "You need to create a character first!" << endl;
		}
	}
	else if (choice == '4')
	{
		// Load inventory from file and use inventory class
		cout << "Starting inventory display" << endl;
	}
	else
	{
		cout << "That was not a valid choice!" << endl;
	}
	if (isRunning())
	{
		string confirm;
		cout << "\nPress enter to continue.." << endl;
		getline(cin, confirm);
	}
}

/* Clears console window */
void StartMenu::clearConsole()
{
	system("cls");
}
/* Pauses the time for set couple of seconds to
allow the user to see their choices more clearly*/
void StartMenu::sleepTimer(int seconds)
{
	this_thread::sleep_for(chrono::seconds(seconds));
}
