#include "../../Headers/Entities/Bank.h"

Bank& Bank::getInstance()
{
    static Bank instance;
    return instance;
}

void Bank::getAllTradesFor(Player& player)
{
}

bool Bank::isTradeAccepted(int fieldIndex)
{
    return false;
}

Trade& Bank::getTrade(int fieldIndex)
{
    return trades[0];
}

const Trade& Bank::getTrade(int fieldIndex) const
{
    return trades[0];
}

void Bank::payGetOutOfJail(Player& player)
{
}

void Bank::takeAllAssets(Player& player)
{
}

void Bank::giveStartingMoney()
{
}
