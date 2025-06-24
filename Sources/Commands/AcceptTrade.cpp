#include "../../Headers/Commands/AcceptTrade.h"

void AcceptTrade::execute() const
{
	if (!data.isGameStarted())
	{
		throw std::logic_error("Game not started.");
	}

	Player& curPl = data.getCurrentPlayer();

	std::cout << "Enter for which property the offer is: ";
	int fieldId;
	std::cin >> fieldId;

	std::cout << "Now, from who is it: ";
	MyString fromPlayer;
	std::cin >> fromPlayer;

	Player& buyer = data.getPlayer(fromPlayer);
	
	if (!data.playerHasTradeOffer(fieldId, buyer))
	{
		throw std::invalid_argument("Trade not found or already accepted.");
	}

	int tradeIndex = data.getTradeIndexInList(fieldId, buyer);
	int tradeAmount = data.getTradeAmount(tradeIndex);

	Property& prop = data.getProperty(fieldId);

	bool toForceSelling = false;

	if (!buyer.hasEnoughBalance(tradeAmount))
	{
		if (!buyer.hasEnoughAssets(tradeAmount))
		{
			std::cout << "Too little assets! Disqualified!";
			buyer.resign();
			data.removeTradesFrom(buyer);
			data.removeAllPropertiesFrom(buyer);
		}

		toForceSelling = true;
	}

	prop.removeMortgage();
	prop.removeOwner();
	curPl.increaseBalance(tradeAmount);

	prop.setOwner(buyer);
	buyer.decreaseBalance(tradeAmount);

	data.acceptTrade(tradeIndex);
	data.printBoard();

	if (toForceSelling)
	{
		data.forcePlayerToSell(buyer, tradeAmount);
	}
}
