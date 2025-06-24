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
	std::cout << "A COP SENT YOU TO JAIL!" << std::endl;
	player.moveTo(jailFieldIndex);
}

void GoToJailField::saveToFile(std::ofstream& ofs) const
{
	const char* type = "GoToJailField";
	int length = strlen(type);
	ofs.write(reinterpret_cast<const char*>(&length), sizeof(length));
	ofs.write(type, length);

	int index = getFieldIndex();
	ofs.write(reinterpret_cast<const char*>(index), sizeof(index));
	ofs.write(reinterpret_cast<const char*>(jailFieldIndex), sizeof(jailFieldIndex));
}

MyString GoToJailField::getPrintInfo() const
{
	return "COP!";
}
