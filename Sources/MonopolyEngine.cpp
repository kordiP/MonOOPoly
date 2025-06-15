#include "../Headers/MonopolyEngine.h"

MonopolyEngine& MonopolyEngine::getInstance()
{
    static MonopolyEngine instance;
    return instance;
}

void MonopolyEngine::run()
{
	srand(time(0));

	CommandInterpretor& commandReader = CommandInterpretor::getInstance();
	MyString input;
	commandReader.executeCommand("Initial");

	do
	{
		std::cin >> input;
		commandReader.executeCommand(input);
	} while (input != "EndGame");
}