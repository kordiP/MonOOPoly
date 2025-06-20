#include "../../../Headers/Entities/Fields/JailField.h"

JailField::JailField(int index, const MyString& content, int feeForEscape) : Field(index, content)
{
	this->feeForEscape = feeForEscape;
}

int JailField::getFeeForEscape() const
{
	return feeForEscape;
}

Field* JailField::clone() const
{
	return new JailField(*this);
}

void JailField::steppedOnBy(Player& player)
{
	player.shouldSkipTurn(true);
}

void JailField::saveToFile(std::ofstream& ofs) const
{
}
