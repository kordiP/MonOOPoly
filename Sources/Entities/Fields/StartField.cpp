#include "../../../Headers/Entities/Fields/StartField.h"

StartField::StartField()
{
}

StartField::StartField(int index, const MyString& content) : Field(index, content, 0)
{
}

Field* StartField::clone() const
{
    return nullptr;
}

void StartField::steppedOnBy(Player& player)
{
}

void StartField::print() const
{
}

void StartField::printDescription() const
{
}

void StartField::saveToFile(std::ofstream& ofs) const
{
}
