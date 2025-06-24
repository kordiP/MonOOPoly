#include "../../Headers/Commands/Resign.h"

void Resign::execute() const
{
	if (!data.isGameStarted())
	{
		throw std::logic_error("Game not started.");
	}

	data.clearBoard();

	Player& curPl = data.getCurrentPlayer();

	curPl.resign();

	data.removeTradesFrom(curPl);
	// todo - remove all properties of curpl
	data.printBoard();
}
