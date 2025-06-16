#pragma once
#include "../Entities/Trade.h"
#include "../Entities/Player.h"
#include "../Utilities/MyVector.hpp"

class Bank
{
private:
    MyVector<Trade> trades;
    Bank() = default;
    ~Bank() = default;

    Bank(const Bank&) = delete;
    Bank& operator=(const Bank&) = delete;
    Bank(Bank&&) = delete;
    Bank& operator=(Bank&&) = delete;

    Trade& getTrade(int fieldIndex);
    const Trade& getTrade(int fieldIndex) const;
public:
    static Bank& getInstance();

    void payGetOutOfJail(Player& player);
    // basically, set property owner to nullptr
    void takeAllAssets(Player& player);
    void giveStartingMoney();

    int getTradeIndexInList(int fieldId, Player& from);
    bool playerHasTradeOffer(int atField, Player& fromPlayer);

    void acceptTrade(int tradeIndex);

    void printAllTradesFor(Player& player);
    int getTradeAmount(int tradeIndex);
    bool isTradeAccepted(int fieldIndex);
};