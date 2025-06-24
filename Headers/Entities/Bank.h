#pragma once
#include "../Entities/Trade.h"
#include "../Entities/Player.h"
#include "../Utilities/MyVector.hpp"
#include "../Utilities/MyString.h"

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
public:
    static Bank& getInstance();

    int getTradeIndexInList(int fieldId, Player& from);
    bool playerHasTradeOffer(int atField, Player& fromPlayer);

    void addTrade(Trade& trade);
    void acceptTrade(int tradeIndex);
    void removeTradesFrom(Player& player);

    void printAllTradesFor(Player& player);
    int getTradeAmount(int tradeIndex);
};