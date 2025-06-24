#pragma once
#include "Entities/Board.h"
#include "Entities/Bank.h"
#include "Entities/Player.h"
#include "Entities/Trade.h"
#include "Entities/Fields/Field.h"
#include "Entities/Cards/CardDeck.h"
#include "Entities/Cards/Card.h"

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
    void printBoard();
    void clearBoard();
    void addPlayer(const MyString& playerName, char fig);

    bool isGameStarted() const;
	bool isGameOver() const;
	int getCurrentPlayersCount() const;

    int getJailIndex() const;
    int getJailTax();
    Field* getFieldAt(int index) const;

    bool playerHasTradeOffer(int atField, Player& fromPlayer);
    int getTradeIndexInList(int atField, Player& fromPlayer);
    int getTradeAmount(int tradeIndex);
    Property& getProperty(int atField);

    void acceptTrade(int tradeIndex);
    void printPlayerTrades(Player& player);

    // + check if owner == curPl
    bool isEligibleForMortgage(int fieldAt);

    void removeTradesFrom(Player& pl);
    void proposeTrade(Trade& trade);

    void forcePlayerToSell(Player& player, int totalAmountNeeded);

    void generateRandomDeck(size_t size);

    void groupPayFrom(Player& player, int amount);
    void groupPayTo(Player& player, int amount);

    void checkTurn();
    void performTurn();

	int getCurrentPlayerIndex() const;
	Player& getPlayer(const MyString& name);
	Player& getCurrentPlayer();
};