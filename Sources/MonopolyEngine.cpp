#include "../Headers/MonopolyEngine.h"

MonopolyEngine& MonopolyEngine::getInstance()
{
    static MonopolyEngine instance;
    return instance;
}

void MonopolyEngine::run()
{
	srand(time(0));

	try
	{
		CommandInterpretor& commandReader = CommandInterpretor::getInstance();
		MyString input;
		commandReader.executeCommand("Initial");

		do
		{
			std::cin >> input;
			commandReader.executeCommand(input);
			input = "";
		} while (input != "EndGame" || !data.isGameOver());

		std::cout << "Exiting game."; 
		// todo -> save to binary
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
}