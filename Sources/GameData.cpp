#include "../Headers//GameData.h"

void GameData::addPlayer(const Player& player)
{
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
