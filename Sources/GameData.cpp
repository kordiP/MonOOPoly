#include "../Headers/GameData.h"
GameData::GameData() : board(Board::getInstance()), bank(Bank::getInstance()), deck(CardDeck::getInstance()) { }

GameData& GameData::getInstance() 
{
	static GameData instance;
	return instance;
}

void GameData::generateBoard()
{
	board.generate();
}

void GameData::printBoard()
{
	board.printBoard();
}

bool GameData::isNameTaken(const MyString& playerName)
{
	for (size_t i = 0; i < players.getSize(); i++)
	{
		if (players[i].getName() == playerName)
		{
			return true;
		}
	}

	return false;
}

void GameData::addPlayer(const MyString& playerName, char fig)
{
	Player player(playerName, fig);
	players.pushBack(player);
}

bool GameData::isGameOver() const
{
	return gameEnded;
}

int GameData::getCurrentPlayersCount() const
{
	return players.getSize();
}

int GameData::getJailIndex() const
{
	return board.getJailIndex();
}

int GameData::getJailTax()
{
	return board.getJailTax();
}

Field* GameData::getFieldAt(int index) const
{
	return board.getField(index);
}

int GameData::getTradeIndexInList(int fieldId, Player& from)
{
	return bank.getTradeIndexInList(fieldId, from);
}

int GameData::getTradeAmount(int tradeIndex)
{
	return bank.getTradeAmount(tradeIndex);
}

Property& GameData::getProperty(int atField)
{
	return dynamic_cast<Property&>(*getFieldAt(atField));
}

void GameData::acceptTrade(int tradeIndex)
{
	bank.acceptTrade(tradeIndex);
}

void GameData::printPlayerTrades(Player& player)
{
}

bool GameData::isEligibleForMortgage(int fieldAt)
{
	return false;
}

void GameData::removeTradesFrom(Player& pl)
{
}

void GameData::sellAllFieldsFrom(Player& pl)
{
}

void GameData::proposeTrade(Trade& trade)
{
}

void GameData::forcePlayerToSell(Player& player, int totalAmountNeeded)
{
	std::cout << "You need to sell some of your properties, please choose which: ";

	while (player.getBalance() < 0)
	{
		std::cout << "<Debt left: " << player.getBalance() << ">" << std::endl;

		board.printPropertiesFor(player);
		std::cout << "Enter the field index to sell: ";
		int index;
		std::cin >> index;

		// todo
	}
}

bool GameData::playerHasTradeOffer(int atField, Player& fromPlayer)
{
	return bank.playerHasTradeOffer(atField, fromPlayer);
}

void GameData::generateRandomDeck(size_t size)
{
	deck.generateRandomDeck(size);
}

void GameData::groupPayFrom(Player& player, int amount)
{
	player.increaseBalance(amount);

	for (size_t i = 0; i < players.getSize(); i++)
	{
		Player& pl = players[i];

		if (pl.isResigned() || pl.getFigure() == player.getFigure())
		{
			continue;
		}

		pl.decreaseBalance(amount / (getCurrentPlayersCount() - 1));
	}
}

void GameData::groupPayTo(Player& player, int amount)
{
	player.decreaseBalance(amount);

	for (size_t i = 0; i < players.getSize(); i++)
	{
		Player& pl = players[i];

		if (pl.isResigned() || pl.getFigure() == player.getFigure())
		{
			continue;
		}

		pl.increaseBalance(amount / (getCurrentPlayersCount() - 1));
	}
}

// just handle who is at turn / who is currPlayer
void GameData::performTurn()
{
	if (players.getSize() <= 0)
	{
		throw std::logic_error("Not initialized, cannot perform turn.");
	}

	if (currentPlayerIndex == -1 || currentPlayerIndex >= players.getSize())
	{
		currentPlayerIndex = 0;
	}

	Player& currPlayer = players[currentPlayerIndex];

	if (currPlayer.isResigned())
	{
		currentPlayerIndex++;
		return;
	}

	if (currPlayer.toSkipTurn())
	{
		currPlayer.shouldSkipTurn(false);
		currentPlayerIndex++;
		return;
	}

	if (getCurrentPlayersCount() == 1)
	{
		gameEnded = true;
		return;
	}

	currentPlayerIndex++;

	board.printBoard();
}

int GameData::getCurrentPlayerIndex() const
{
	return currentPlayerIndex;
}

Player& GameData::getPlayer(const MyString& name)
{
	for (size_t i = 0; i < players.getSize(); i++)
	{
		if (players[i].getName() == name)
		{
			return players[i];
		}
	}

	throw std::invalid_argument("Player with given name does not exist.");
}

Player& GameData::getCurrentPlayer()
{
	return players[currentPlayerIndex];
}
