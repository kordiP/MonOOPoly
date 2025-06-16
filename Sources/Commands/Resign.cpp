#include "../../Headers/Commands/Resign.h"

void Resign::execute() const
{
	if (data.getCurrentPlayerIndex() == -1)
	{
		throw std::logic_error("Game not started.");
	}

	Player& curPl = data.getCurrentPlayer();

	curPl.resign();

	data.removeTradesFrom(curPl);
	data.sellAllFieldsFrom(curPl);
	data.printBoard();
}
