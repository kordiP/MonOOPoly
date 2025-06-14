#pragma once
#include "Card.h"

class MovePositionCard : public Card
{
public:
	void applyEffectTo(Player& player) const override;
	void printCardInfo() const override;
};