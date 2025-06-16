#include "../../../Headers/Entities/Cards/GroupPaymentCard.h"

GroupPaymentCard::GroupPaymentCard() 
	//: data(GameData::getInstance())
{
}

GroupPaymentCard::GroupPaymentCard(int amount) : amountToPay(amount)
//, data(GameData::getInstance()) 
{}

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
		//data.groupPayTo(player, amountToPay);
	}
	else
	{
		//data.groupPayFrom(player, amountToPay);
	}
}
