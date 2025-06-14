#pragma once
#include "Entities/Board.h"
#include "Entities/Bank.h"
#include "Entities/Player.h"
#include "Entities/Cards/CardDeck.h"

class GameData
{
private:
    bool gameEnded = false;
    int currentPlayerIndex = 0;

    Board& board;
    MyVector<Player> players;
    Bank& bank;
    CardDeck& deck;
public:
    void addPlayer(const Player& player);

	bool isGameOver() const;
	int getCurrentPlayersCount() const;

	int getCurrentPlayerIndex() const;
	Player& getPlayer(const MyString& name);
	Player& getCurrentPlayer();
};