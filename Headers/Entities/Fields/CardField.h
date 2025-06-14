#pragma once
#include "Field.h"
#include "../CardDeck.h"

class CardField : public Field
{
private:
	CardDeck& deck;
public:
	CardField();
	void steppedOnBy(Player* player) override; // drawCard from deck, card->applyEffect(player)
	void print() const override;
};