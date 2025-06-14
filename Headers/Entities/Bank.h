#pragma once
#include "../Entities/Trade.h"
#include "../Entities/Player.h"
#include "../Utilities/MyVector.hpp"

class Bank
{
private:
    MyVector<Trade> trades;
    Bank();
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

    void takeMoneyFrom(Player& player, double amount);
    void giveMoneyTo(Player& player, double amount);

    void getAllTradesFor(Player& player);
    bool isTradeAccepted(int fieldIndex);
};