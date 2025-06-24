#include "../../Headers/Commands/RollDice.h"

void RollDice::execute() const
{
	if (!data.isGameStarted())
	{
		throw std::logic_error("Game not started.");
	}

	if (!data.checkTurn())
	{
		data.performTurn();
		return;
	}

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
		data.performTurn();
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
			data.performTurn();
		}
		else
		{
			std::cout << "Okay, next turn you will have the same option. Press anything to continue." << std::endl;
			MyString wait;
			std::cin >> wait;
			curPl.resetPairCount();
			curPl.shouldSkipTurn(false);
			data.performTurn();

			data.clearBoard();
			data.printBoard();
			return;
		}
	}

	curPl.moveBy(diceOne + diceTwo);
	std::cout << "Postition now: " << curPl.getPositionIndex() << std::endl;

	// if this is < 0 it means we have passed the start
	int diff = curPl.getPositionIndex() - (diceOne + diceTwo);
	if (diff < 0)
	{
		data.getFieldAt(0)->steppedOnBy(curPl);
	}

	data.getFieldAt(curPl.getPositionIndex())->steppedOnBy(curPl);

	if (curPl.getBalance() < 0)
	{
		data.forcePlayerToSell(curPl, curPl.getBalance());
	}
	MyString wait;
	std::cout << "Enter anything to continue. ";
	std::cin >> wait;

	data.clearBoard();
	if (diceOne == diceTwo)
	{
		if (curPl.getPositionIndex() == jailAt)
		{
			data.performTurn();
		}
	}
	else
	{
		data.performTurn();
	}
	
	data.printBoard();
}
