#include "../../Headers/Commands/RollDice.h"

void RollDice::execute() const
{
	if (!data.isGameStarted())
	{
		throw std::logic_error("Game not started.");
	}

	data.clearBoard();

	data.performTurn();

	Player& curPl = data.getCurrentPlayer();

	size_t diceOne = rand() % 6 + 1;
	size_t diceTwo = rand() % 6 + 1;

	int jailAt = data.getJailIndex();

	std::cout << "Rolled a " << diceOne << " and a " << diceTwo << std::endl;

	if (diceOne == diceTwo)
	{
		curPl.pairThrown();
	}

	if (curPl.getConsecPairsCount() == 3)
	{
		std::cout << "Three consecutive pairs? Cheater behaviour, jail." << std::endl;

		curPl.moveTo(jailAt);
		data.getFieldAt(jailAt)->steppedOnBy(curPl);
		return;
	}

	if (curPl.getPositionIndex() == jailAt && diceOne == diceTwo)
	{
		std::cout << "Lucky you, no longer in jail. The pair frees you!" << std::endl;
	}

	else if (curPl.getPositionIndex() == jailAt && diceOne != diceTwo)
	{
		std::cout << "The roll was unsuccessfull. Would you like to pay to get out? It costs " 
			<< data.getJailTax() << ". If so, type \"Pay\"" << std::endl;
		MyString wantsToPay;
		std::cin >> wantsToPay;

		if (wantsToPay == "Pay")
		{
			std::cout << "You will now go to the free parking area." << std::endl;
			curPl.decreaseBalance(data.getJailTax());
			diceOne = diceTwo = 2;
		}
		else
		{
			curPl.resetPairCount();
			return;
		}
	}

	curPl.moveBy(diceOne + diceTwo);

	// if this is < 0 it means we have passed the start
	if (curPl.getPositionIndex() - (diceOne + diceTwo) < 0)
	{
		data.getFieldAt(0)->steppedOnBy(curPl);
	}

	data.getFieldAt(curPl.getPositionIndex())->steppedOnBy(curPl);
	data.printBoard();
}
