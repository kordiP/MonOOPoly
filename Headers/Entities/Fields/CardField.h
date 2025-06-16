#pragma once
#include "Field.h"
#include "../Cards/CardDeck.h"

class CardField : public Field
{
private:
	CardDeck& deck;
public:
	CardField();
	CardField(int index, const MyString& descr);

	Field* clone() const override;
	void steppedOnBy(Player& player) override;// drawCard from deck, card->applyEffect(player)
	void saveToFile(std::ofstream& ofs) const override;
};