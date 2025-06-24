#pragma once
#include "Card.h"

class PaymentCard : public Card
{
private:
	int amount = 100;
public:
	PaymentCard() = default;
	PaymentCard(int amount);

	Card* clone() const override;
	void printCardInfo() const override;
	void applyEffectTo(Player& player) const override;
};