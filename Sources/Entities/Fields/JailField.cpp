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
	std::cout << "You are in jail! You will skip the next move.";
	player.shouldSkipTurn(true);
	player.resetPairCount();
}

void JailField::saveToFile(std::ofstream& ofs) const
{
	// todo
}

MyString JailField::getPrintInfo() const
{
	return "JAIL";
}
