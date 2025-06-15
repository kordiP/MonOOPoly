#pragma once
#include "Card.h"
#include "GroupPaymentCard.h"
#include "PaymentCard.h"
#include "MovePositionCard.h"
#include "../Player.h"
#include "../../Utilities/Stack.hpp"
#include <iostream>

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

    void generateRandomDeck(size_t size);
    void drawCard(Player& player);
};