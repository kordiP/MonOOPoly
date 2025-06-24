#include "../../../Headers/Entities/Fields/GoToJailField.h"

GoToJailField::GoToJailField(int index, const MyString& descr, int jailIndex) : Field(index, descr)
{
	this->jailFieldIndex = jailIndex;
}

Field* GoToJailField::clone() const
{
	return new GoToJailField(*this);
}

void GoToJailField::steppedOnBy(Player& player)
{
	std::cout << "COP! Straight to jail." << std::endl;
	player.moveTo(jailFieldIndex);
}

void GoToJailField::saveToFile(std::ofstream& ofs) const
{
	// todo
}

MyString GoToJailField::getPrintInfo() const
{
	return "COP!";
}
