#include "../../Headers/Commands/ViewTrades.h"
void ViewTrades::execute() const
{
	if (data.getCurrentPlayerIndex() == -1)
	{
		throw std::logic_error("Game not started.");
	}

	Player& curPl = data.getCurrentPlayer();

	data.printPlayerTrades(curPl);
	data.printBoard();
}
