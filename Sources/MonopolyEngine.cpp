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
		Serializer& ser = Serializer::getInstance();
		MyString input;
		commandReader.executeCommand("Initial");

		do
		{
			input = "";
			std::cin >> input;
			commandReader.executeCommand(input);
		} while (input != "EndGame" && !data.isGameOver());

		std::cout << "Exiting game. Progress will be saved."; 
		ser.createGameSave();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
}