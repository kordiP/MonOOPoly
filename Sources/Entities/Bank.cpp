#include "../../Headers/Entities/Bank.h"

Bank& Bank::getInstance()
{
    static Bank instance;
    return instance;
}

void Bank::printAllTradesFor(Player& player)
{
    for (size_t i = 0; i < trades.getSize(); i++)
    {
        if (trades[i].getReceiverName() == player.getName() && !trades[i].gotAccepted())
        {
            trades[i].printTrade();
        }
    }
}

int Bank::getTradeIndexInList(int fieldId, Player& from)
{
    for (size_t i = 0; i < trades.getSize(); i++)
    {
        if (trades[i].getSenderName() == from.getName() && !trades[i].gotAccepted())
        {
            if (trades[i].getFieldIndex() == fieldId)
            {
                return i;
            }
        }
    }
}

bool Bank::playerHasTradeOffer(int atField, Player& fromPlayer)
{
    for (size_t i = 0; i < trades.getSize(); i++)
    {
        if (trades[i].getSenderName() == fromPlayer.getName() && !trades[i].gotAccepted())
        {
            if (trades[i].getFieldIndex() == atField)
            {
                return true;
            }
        }
    }

    return false;
}

void Bank::addTrade(Trade& trade)
{
    trades.pushBack(trade);
}

void Bank::acceptTrade(int tradeIndex)
{
    trades[tradeIndex].acceptOffer();
}

void Bank::removeTradesFrom(Player& player)
{
    for (size_t i = 0; i < trades.getSize(); i++)
    {
        if (trades[i].getReceiverName() == player.getName() || trades[i].getSenderName() == player.getName())
        {
            trades.removeAt(i);
        }
    }
}

int Bank::getTradeAmount(int tradeIndex)
{
    return trades[tradeIndex].getRequestedAmount();
}