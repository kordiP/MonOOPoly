#include "../../../Headers/Entities/Fields/CardField.h"

CardField::CardField() : deck(CardDeck::getInstance()) { }

CardField::CardField(int index, const MyString& descr) : deck(CardDeck::getInstance()), Field(index, descr) { }

Field* CardField::clone() const
{
    return new CardField(*this);
}

void CardField::steppedOnBy(Player& player)
{
    std::cout << "You draw a card." << std::endl;
    deck.drawCard(player);
}

void CardField::saveToFile(std::ofstream& ofs) const
{
	const char* type = "CardField";
	int length = strlen(type);
	ofs.write(reinterpret_cast<const char*>(&length), sizeof(length));
	ofs.write(type, length);

	int index = getFieldIndex();
	ofs.write(reinterpret_cast<const char*>(index), sizeof(index));
}

MyString CardField::getPrintInfo() const
{
    return "CARD";
}
