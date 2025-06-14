#pragma once
#include "Player.h"

class Trade
{
private:
	Player* sender = nullptr;
	Player* receiver = nullptr;
	bool isAccepted = false;

	MyString offer;
	// for which property it is
	int fieldIndex;
	int amount;

public:
	Trade() = default;
	Trade(Player* sender, Player* receiver, const MyString& offer, int fieldIndex, int amount);

	int getSenderIndex() const;
	int getReceiverIndex() const;
	bool gotAccepted() const;
	int getFieldIndex() const;
	int getRequestedAmount() const;

	void printTrade() const;
	void acceptOffer();
	void saveToFile(std::ofstream& ofs) const;
};