#include "../Headers/Entities/Bank.h"
#include "../Headers/Entities/Board.h"
#include "../Headers/Entities/Cards/CardDeck.h"
#include "../Headers/Entities/Fields/Field.h"
#include "../Headers/Entities/Fields/Property.h"
#include "../Headers/Entities/Player.h"
#include "../Headers/Entities/Trade.h"
#include "../Headers/GameData.h"
#include "../Headers/Utilities/MyString.h"
#include <iostream>
#include <ostream>
#include <windows.h>
#include "../Headers/Utilities/Colors.h"

GameData::GameData() : board(Board::getInstance()), bank(Bank::getInstance()), deck(CardDeck::getInstance()) {}

GameData& GameData::getInstance()
{
	static GameData instance;
	return instance;
}

void GameData::generateBoard()
{
	board.generate();
	currentPlayerIndex = 0;
}

void GameData::printBoard()
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, Colors::DEFAULT_COLOR);

	Player& curPl = getCurrentPlayer();
	board.printBoard();

	for (size_t i = 0; i < players.getSize(); i++)
	{
		if (i == currentPlayerIndex)
		{
			SetConsoleTextAttribute(hConsole, Colors::DEFAULT_INVERSE);
			std::cout << ">";
			SetConsoleTextAttribute(hConsole, Colors::DEFAULT_COLOR);

		}
		std::cout << " " << players[i].getFigure()
			<< " | name: " << players[i].getName()
			<< " | current position: " << players[i].getPositionIndex()
			<< " | balance: " << players[i].getBalance() << "$" << std::endl;
	}
}

void GameData::clearBoard()
{
	std::cout << "\033[;H"; // Moves cursor to the top left
	std::cout << "\033[J"; // Clears the console
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

bool GameData::isGameStarted() const
{
	if (players.getSize() <= 0)
	{
		return false;
	}

	return true;
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
	bank.printAllTradesFor(player);
}

int GameData::getBoardSize() const
{
	return board.getBoardSize();
}

bool GameData::isEligibleForMortgage(int fieldAt)
{
	Property& prop = getProperty(fieldAt);
	Player& curPl = getCurrentPlayer();

	if (!prop.isOwner(curPl))
	{
		return false;
	}

	int index = prop.getFieldIndex();
	int neighbourPos = prop.getFieldIndex() % 4;

	Property& n1 = getProperty(index + 1);
	Property& n2 = getProperty(index + 2);

	switch (neighbourPos)
	{
	case 2:
		n1 = getProperty(index + 1);
		n2 = getProperty(index - 1);
		break;
	case 3:
		n1 = getProperty(index - 1);
		n2 = getProperty(index - 2);
		break;
	default:
		throw std::logic_error("Something went wrong in calculating neighbours' positions.");
		break;
	}

	if (!n1.isOwner(curPl) || !n2.isOwner(curPl))
	{
		return false;
	}

	return true;
}

void GameData::removeTradesFrom(Player& pl)
{
	bank.removeTradesFrom(pl);
}

void GameData::proposeTrade(Trade& trade)
{
	bank.addTrade(trade);
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

		if (index % 4 == 0)
		{
			throw std::invalid_argument("Non sellable field.");
		}

		Property* prop = dynamic_cast<Property*>(getFieldAt(index));
		if (prop->isOwner(player))
		{
			player.increaseBalance(prop->getPurchasePrice());
			prop->removeOwner();
			prop->removeMortgage();
		}
		else
		{
			throw std::invalid_argument("This property is not yours.");
		}
	}
}

void GameData::removeAllPropertiesFrom(Player& player)
{
	board.removePropertiesOwner(player);
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

bool GameData::checkTurn() 
{
	Player& currPlayer = getCurrentPlayer();
	if (!isGameStarted())
	{
		throw std::logic_error("Not initialized, cannot perform turn.");
	}

	if (isGameOver())
	{
		throw std::logic_error("Game already finished.");
	}

	if (currPlayer.isResigned())
	{
		std::cout << "Your turn was skipped, you resigned. Enter anything to continue." << std::endl;
		MyString wait;
		std::cin >> wait;

		return false;
	}

	else if (currPlayer.toSkipTurn())
	{
		std::cout << "Your turn was skipped, because it needed to be. Enter anything to continue." << std::endl;
		MyString wait;
		std::cin >> wait;
		currPlayer.shouldSkipTurn(false);

		return false;
	}

	else if (getCurrentPlayersCount() == 1)
	{
		gameEnded = true;
		return false;
	}

	return true;
}

void GameData::performTurn()
{
	clearBoard();
	currentPlayerIndex++;
	
	if (currentPlayerIndex >= players.getSize())
	{
		currentPlayerIndex = 0;
	}
	printBoard();
}

int GameData::getPlayersCount() const
{
	return players.getSize();
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

Player& GameData::getPlayerAt(int id)
{
	return players[id];
}

Player& GameData::getCurrentPlayer()
{
	return players[currentPlayerIndex];
}
