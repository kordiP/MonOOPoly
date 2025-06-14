#pragma once
#include "Card.h"

class GroupPaymentCard : public Card
{
private:
	int amount;
public:
	GroupPaymentCard() = default;
	GroupPaymentCard(int amount);

	Card* clone() const override;
	void printCardInfo() const override;
	void applyEffectTo(Player& player) const override;
};