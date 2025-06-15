#pragma once
#include "Card.h"
#include "../Player.h"
#include "../../Utilities/Stack.hpp"

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
    void addCard(const Card& card); // for when it's still empty, fill it first then use it
};