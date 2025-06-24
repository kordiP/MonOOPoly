#pragma once
#include "Card.h"

class GameData;

class GroupPaymentCard : public Card
{
private:
	int amountToPay = 100;
	GameData& data;
public:
	GroupPaymentCard();
	GroupPaymentCard(int amount);

	Card* clone() const override;
	void printCardInfo() const override;
	void applyEffectTo(Player& player) const override;
};