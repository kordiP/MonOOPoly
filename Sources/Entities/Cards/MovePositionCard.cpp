#include "../../../Headers/Entities/Cards/MovePositionCard.h"

MovePositionCard::MovePositionCard(int moveBy)
{
	this->moveBy = moveBy;
}

Card* MovePositionCard::clone() const
{
	return new MovePositionCard(*this);
}

void MovePositionCard::printCardInfo() const
{
	if (moveBy >= 0)
	{
		std::cout << "You will be moved forwards with " << moveBy << " positions." << std::endl;
	}
	else
	{
		std::cout << "You will be moved backwards with " << moveBy << " positions." << std::endl;
	}
}

void MovePositionCard::applyEffectTo(Player& player) const
{
	player.moveBy(moveBy);
}
