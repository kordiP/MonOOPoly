#include "../../../Headers/Entities/Cards/GroupPaymentCard.h"
#include "../../../Headers/GameData.h"

GroupPaymentCard::GroupPaymentCard(): data(GameData::getInstance())
{ }

GroupPaymentCard::GroupPaymentCard(int amount) : amountToPay(amount), data(GameData::getInstance()) 
{ }

Card* GroupPaymentCard::clone() const
{
	return new GroupPaymentCard(*this);
}

void GroupPaymentCard::printCardInfo() const
{
	if (amountToPay <= 0)
	{
		std::cout << "All players need to pay you " << amountToPay << std::endl;
	}
	else
	{
		std::cout << "You give everyone money." << amountToPay << std::endl;
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
