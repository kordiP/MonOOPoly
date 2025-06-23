#include "../../Headers/Commands/AcceptTrade.h"

void AcceptTrade::execute() const
{
	if (data.getCurrentPlayerIndex() == -1)
	{
		throw std::logic_error("Game not started.");
	}

	data.clearBoard();

	Player& curPl = data.getCurrentPlayer();

	std::cout << "Enter for which property the offer is: ";
	int fieldId;
	std::cin >> fieldId;

	std::cout << "Now, from who is it: ";
	MyString fromPlayer;
	std::cin >> fromPlayer;

	Player& fromPl = data.getPlayer(fromPlayer);
	
	if (!data.playerHasTradeOffer(fieldId, fromPl))
	{
		throw std::invalid_argument("Trade not found or already accepted.");
	}

	int tradeIndex = data.getTradeIndexInList(fieldId, fromPl);
	int tradeAmount = data.getTradeAmount(tradeIndex);

	Property& prop = data.getProperty(fieldId);

	bool toForceSelling = false;

	if (!curPl.hasEnoughBalance(tradeAmount))
	{
		if (!curPl.hasEnoughAssets(tradeAmount))
		{
			throw std::logic_error("Not possible for user to collect enough funds.");
		}

		toForceSelling = true;
	}

	prop.removeMortgage();
	prop.removeOwner();
	fromPl.increaseBalance(tradeAmount);

	prop.setOwner(curPl);
	curPl.decreaseBalance(tradeAmount);

	data.acceptTrade(tradeIndex);
	data.printBoard();

	if (toForceSelling)
	{
		data.forcePlayerToSell(curPl, tradeAmount);
	}
}
