#pragma once
#include "Card.h"

class MovePositionCard : public Card
{
private:
	int moveBy;
public:
	MovePositionCard() = default;
	MovePositionCard(int moveBy);

	Card* clone() const override;
	void printCardInfo() const override;
	void applyEffectTo(Player& player) const override;
};