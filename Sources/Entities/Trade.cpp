#include "../../Headers/Entities/Trade.h"

Trade::Trade(Player* sender, Player* receiver, const MyString& offer, int fieldIndex, int amount)
{
	this->sender = sender;
	this->receiver = receiver;
	this->offer = offer;
	this->fieldIndex = fieldIndex;
	this->amount = amount;
}

void Trade::acceptOffer()
{
	isAccepted = true;
}

void Trade::printTrade() const
{
	std::cout << "Sender: " << sender->getName() << std::endl;
	std::cout << "Receiver: " << receiver->getName() << std::endl;
	std::cout << "Offer: " << offer << std::endl;
	std::cout << "Field at: " << fieldIndex << std::endl;
	std::cout << "Amount requested for buying: " << amount << std::endl;
}

int Trade::getRequestedAmount() const
{
	return amount;
}

int Trade::getFieldIndex() const
{
	return fieldIndex;
}

bool Trade::gotAccepted() const
{
	return isAccepted;
}

const MyString& Trade::getReceiverName() const
{
	return receiver->getName();
}

const MyString& Trade::getSenderName() const
{
	return sender->getName();
}