#include "../../Headers/Commands/RollDice.h"

void RollDice::execute() const
{
	if (data.getCurrentPlayerIndex() == -1)
	{
		throw std::logic_error("Game not started.");
	}

	Player& curPl = data.getCurrentPlayer();

	size_t diceOne = rand() % 6 + 1;
	size_t diceTwo = rand() % 6 + 1;

	int jailAt = data.getJailIndex();
	Field* jail = data.getFieldAt(jailAt);

	data.performTurn();

	std::cout << "Rolled a " << diceOne << " and a " << diceTwo << std::endl;

	if (curPl.getPositionIndex() == jailAt)
	{

	}

	if (diceOne == diceTwo)
	{
		curPl.pairThrown();
	}

	if (curPl.getConsecPairsCount() == 3)
	{
		std::cout << "Three consecutive pairs? Cheater behaviour, jail." << std::endl;

		curPl.moveTo(jailAt);
		curPl.resetPairCount();
		curPl.shouldSkipTurn(true);
	}
}
