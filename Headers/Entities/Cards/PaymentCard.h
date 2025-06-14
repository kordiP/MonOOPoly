#pragma once
#include "Card.h"

class PaymentCard : public Card
{
private:
	int amount;
public:
	PaymentCard() = default;
	PaymentCard(int amount);

	Card* clone() const override;
	void printCardInfo() const override;
	void applyEffectTo(Player& player) const override;
};