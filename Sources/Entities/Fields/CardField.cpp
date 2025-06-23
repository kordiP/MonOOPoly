#include "../../../Headers/Entities/Fields/CardField.h"

CardField::CardField() : deck(CardDeck::getInstance()) { }

CardField::CardField(int index, const MyString& descr) : deck(CardDeck::getInstance()), Field(index, descr) { }

Field* CardField::clone() const
{
    return new CardField(*this);
}

void CardField::steppedOnBy(Player& player)
{
    deck.drawCard(player);
}

void CardField::saveToFile(std::ofstream& ofs) const
{
    // todo
}
