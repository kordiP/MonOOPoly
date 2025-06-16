#include "../../../Headers/Entities/Fields/CardField.h"

CardField::CardField() : deck(CardDeck::getInstance())
{
}

CardField::CardField(int index, const MyString& descr) : deck(CardDeck::getInstance()), Field(index, descr)
{
}

Field* CardField::clone() const
{
    return nullptr;
}

void CardField::steppedOnBy(Player& player)
{
}

void CardField::print() const
{
}

void CardField::printDescription() const
{
}

void CardField::saveToFile(std::ofstream& ofs) const
{
}
