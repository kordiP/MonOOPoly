#include "../../../Headers/Entities/Cards/GroupPaymentCard.h"

PaymentCard::PaymentCard(int amount)
{
    this->amount = amount;
}

Card* PaymentCard::clone() const
{
    return new PaymentCard(*this);
}

void PaymentCard::printCardInfo() const
{
	if (amount <= 0)
	{
		std::cout << "You give money." << std::endl;
	}
	else
	{
		std::cout << "You take money." << std::endl;
	}
}

void PaymentCard::applyEffectTo(Player& player) const
{
	if (amount <= 0)
	{
		player.decreaseBalance(amount);
	}
	else
	{
		player.increaseBalance(amount);
	}
}
