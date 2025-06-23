#include "../../Headers/Commands/ViewTrades.h"
void ViewTrades::execute() const
{
	if (data.getCurrentPlayerIndex() == -1)
	{
		throw std::logic_error("Game not started.");
	}

	data.clearBoard();

	Player& curPl = data.getCurrentPlayer();

	data.printPlayerTrades(curPl);

	std::cout << "Press enter to continue. " << std::endl;
	MyString resp;
	std::cin >> resp;

	data.printBoard();
}
