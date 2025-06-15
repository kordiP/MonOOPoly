#include "../../Headers/Commands/StartNewGame.h"

void StartNewGame::execute() const
{
	MyVector<char> figures;
	figures.pushBack('!');
	figures.pushBack('@');
	figures.pushBack('#');
	figures.pushBack('$');
	figures.pushBack('%');
	figures.pushBack('^');

	const MyString endInput = "Play!";
	std::cout << "Enter names for up to 6 players. When finished, just type \"" << endInput << "\"" << std::endl;

	for (size_t i = 0; i < 6; i++)
	{
		MyString playerName;
		std::cout << "Enter player " << i + 1 << "'s name: ";
		std::cin >> playerName;

		if (playerName == endInput)
		{
			if (i < 2)
			{
				std::cout << "Hey, you need atleast 2 players, come on." << std::endl;
				i--;
				continue;				
			}
			
			if (data.isNameTaken(playerName))
			{
				std::cout << "Names should be unique." << std::endl;
				i--;
				continue;
			}

			break;
		}

		data.addPlayer(playerName, figures[i]);
	}

	// we have 3 types of cards -> two of each, will be circulated to bottom when drawn
	size_t cardDeckSize = data.getCurrentPlayersCount() * 6;

	data.generateRandomDeck(cardDeckSize);
	data.generateBoard();
	data.performTurn();
}