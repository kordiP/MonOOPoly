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

	data.performTurn();

	std::cout << "Rolled a " << diceOne << " and a " << diceTwo << std::endl;

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

	if (curPl.getPositionIndex() == jailAt && diceOne == diceTwo)
	{
		std::cout << "Lucky you, no longer in jail. The pair frees you!" << std::endl;
	}
	else if (curPl.getPositionIndex() == jailAt)
	{
		std::cout << "The roll was unsuccessfull. Would you like to pay to get out? If so, type \"Pay\"" << std::endl;
		MyString wantsToPay;
		std::cin >> wantsToPay;

		if (wantsToPay == "Pay")
		{
			curPl.decreaseBalance(data.getJailTax());
		}
		else
		{
			curPl.resetPairCount();
			return;
		}
	}

	curPl.moveBy(diceOne + diceTwo);
	Field* next = data.getFieldAt(curPl.getPositionIndex());
	next->steppedOnBy(curPl);
}
