#include "../../../Headers/Entities/Fields/GoToJailField.h"

GoToJailField::GoToJailField()
{
}

GoToJailField::GoToJailField(int index, const MyString& descr, int jailIndex) : Field(index, descr)
{
	this->jailFieldIndex = jailIndex;
}

Field* GoToJailField::clone() const
{
	return nullptr;
}

void GoToJailField::steppedOnBy(Player& player)
{
}

void GoToJailField::print() const
{
}

void GoToJailField::printDescription() const
{
}

void GoToJailField::saveToFile(std::ofstream& ofs) const
{
}
