#include "../Headers//GameData.h"
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

void GameData::addPlayer(const MyString& playerName)
{
	Player player(playerName);
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

Field* GameData::getFieldAt(int index) const
{
	return board.getField(index);
}

Card* GameData::generateRandomCard() const
{
	size_t num = rand() % 3 + 1;

	switch (num)
	{
	case 1:
		return new GroupPaymentCard;
		break;
	case 2:
		return new PaymentCard;
		break;
	case 3:
		return new MovePositionCard;
		break;
	default:
		return nullptr;
		break;
	}
}

void GameData::addCardToDeck(Card* card)
{
	deck.addCard(*card);
}

// just handle who is at turn / who is currPlaya
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
