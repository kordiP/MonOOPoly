#pragma once
#include "../Player.h"

class Card
{
public:
	Card() = default;
	virtual ~Card() = default;

	virtual Card* clone() const = 0;
	virtual void printCardInfo() const = 0;
	virtual void applyEffect(Player& player) const = 0;
};