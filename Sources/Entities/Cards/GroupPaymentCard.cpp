#include "../../../Headers/Entities/Cards/GroupPaymentCard.h"

GroupPaymentCard::GroupPaymentCard()
{
}

GroupPaymentCard::GroupPaymentCard(int amount) : amountToPay(amount) {}

Card* GroupPaymentCard::clone() const
{
	return new GroupPaymentCard(*this);
}

void GroupPaymentCard::printCardInfo() const
{
	if (amountToPay <= 0)
	{
		std::cout << "All players need to pay current player." << std::endl;
	}
	else
	{
		std::cout << "Current player gives everyone money." << std::endl;
	}
}

void GroupPaymentCard::applyEffectTo(Player& player) const
{
	if (amountToPay < 0)
	{
		data.groupPayTo(player, amountToPay);
	}
	else
	{
		data.groupPayFrom(player, amountToPay);
	}
}
