#pragma once
#include "Entities/Board.h"
#include "Entities/Bank.h"
#include "Entities/Player.h"
#include "Entities/Fields/Field.h"
#include "Entities/Cards/CardDeck.h"
#include "Entities/Cards/Card.h"
#include "Entities/Cards/GroupPaymentCard.h"
#include "Entities/Cards/PaymentCard.h"
#include "Entities/Cards/MovePositionCard.h"

class GameData
{
private:
    bool gameEnded = false;
    int currentPlayerIndex = -1;

    Board& board;
    MyVector<Player> players;
    Bank& bank;
    CardDeck& deck;

    GameData();
    ~GameData() = default;

    GameData(const GameData&) = delete;
    GameData& operator=(const GameData&) = delete;
    GameData(GameData&&) = delete;
    GameData& operator=(GameData&&) = delete;
public:
    static GameData& getInstance();
    bool isNameTaken(const MyString& playerName);
    void generateBoard();
    void addPlayer(const MyString& playerName);

	bool isGameOver() const;
	int getCurrentPlayersCount() const;

    int getJailIndex() const;
    Field* getFieldAt(int index) const;

    Card* generateRandomCard() const;
    void addCardToDeck(Card* card);

    void performTurn();

	int getCurrentPlayerIndex() const;
	Player& getPlayer(const MyString& name);
	Player& getCurrentPlayer();
};