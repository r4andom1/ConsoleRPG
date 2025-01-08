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
		UtilityFunctions::clearConsole();
		displayChoices();
		menuChoice(UtilityFunctions::userChoice());
	}
}

void StartMenu::displayChoices() const
{
	displayStartMenuTitle();
	cout << "Welcome to ConsoleRPG!" << endl;
	cout << endl;
	cout << "1) Start Game" << endl;
	cout << "2) Create Character" << endl;
	cout << "3) View your current character" << endl;
	cout << "4) Check inventory from last session" << endl;
	cout << "q) Exit Game" << endl;
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
		// Create game object, pass in the players character and start game here!
		if (m_character != nullptr)
		{
			Game game(*m_character);
			game.run();
		}
		else
			cout << "Create a character before starting the game!" << endl;
	}
	else if (choice == '2')
	{
		cout << "Starting character creation.. " << endl;
		if (m_character == nullptr)
		{
			m_character = new CharacterCreator();
			m_character->createCharacter();
		}
		else
			cout << "You already have a character created! " << endl;
	}
	else if (choice == '3')
	{
		if (m_character != nullptr)
			cout << m_character->toString() << endl;
		else
			cout << "You need to create a character first!" << endl;
	}
	else if (choice == '4')
	{
		// Load inventory from file and use inventory class
		cout << "Starting inventory display" << endl;
		Inventory inventory(*m_character);
		inventory.displayInventory();
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

void StartMenu::displayStartMenuTitle() const
{
cout << R"(
	____ ____  _   _  ____  _____ _      ____  _____ ____  
	/ ___|  _ \| | | |/ ___|| ____| |    |  _ \| ____|  _ \ 
| |   | |_) | |_| | |  _|  _| | |    | |_) |  _| | |_) |
| |___|  __/|  _  | |_| | |___| |___ |  _ <| |___|  _ < 
	\____|_|   |_| |_|\____|_____|_____|_| \_\_____|_| \_\
)";
}
