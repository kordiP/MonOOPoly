#pragma once
#include "Card.h"
#include "../../GameData.h"

class GroupPaymentCard : public Card
{
private:
	int amountToPay = 0;
	GameData& data = GameData::getInstance();
public:
	GroupPaymentCard() = default;
	GroupPaymentCard(int amount);

	Card* clone() const override;
	void printCardInfo() const override;
	void applyEffectTo(Player& player) const override;
};