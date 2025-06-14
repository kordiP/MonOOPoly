#pragma once
#include "Card.h"
#include "../Player.h"

class CardDeck
{
private:
    Stack<Card> deck;

    CardDeck();
    ~CardDeck() = default;

    CardDeck(const CardDeck&) = delete;
    CardDeck& operator=(const CardDeck&) = delete;
    CardDeck(CardDeck&&) = delete;
    CardDeck& operator=(CardDeck&&) = delete;
public:
    static CardDeck& getInstance();
    void drawCard(Player& player);
};