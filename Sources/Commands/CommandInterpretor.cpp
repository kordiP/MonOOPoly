#include "../../Headers/Commands/CommandInterpretor.h"

CommandInterpretor::~CommandInterpretor()
{
	delete currCommand;
	currCommand = nullptr;
}

CommandInterpretor& CommandInterpretor::getInstance()
{
    static CommandInterpretor instance;
    return instance;
}

void CommandInterpretor::executeCommand(const MyString& command)
{
	if (command == "Initial")
	{
		currCommand = new WelcomeScreen();
	}
	else if (command == "NewGame")
	{
		currCommand = new StartNewGame();
	}
	else if (command == "ContinueGame")
	{
		currCommand = new ContinueGame();
	}
	else if (command == "AcceptTrade")
	{
		currCommand = new AcceptTrade();
	}
	else if (command == "HelpMenu")
	{
		currCommand = new HelpMenu();
	}
	else if (command == "ProposeTrade")
	{
		currCommand = new ProposeTrade();
	}
	else if (command == "Resign")
	{
		currCommand = new Resign();
	}
	else if (command == "RollDice")
	{
		currCommand = new RollDice();
	}
	else if (command == "SellProperty")
	{
		currCommand = new SellProperty();
	}
	else if (command == "SetMortgage")
	{
		currCommand = new SetMortgage();
	}
	else if (command == "HelpMenu")
	{
		currCommand = new HelpMenu();
	}
	else if (command == "ViewTrades")
	{
		currCommand = new ViewTrades();
	}
	else
	{
		currCommand = nullptr;
		std::cout << "Not recognized command." << std::endl;
		return;
	}

	currCommand->execute();
}