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
	const char* type = "JailField";
	int length = strlen(type);
	ofs.write(reinterpret_cast<const char*>(&length), sizeof(length));
	ofs.write(type, length);

	int index = getFieldIndex();
	ofs.write(reinterpret_cast<const char*>(index), sizeof(index));

	ofs.write(reinterpret_cast<const char*>(&feeForEscape), sizeof(feeForEscape));
}

MyString JailField::getPrintInfo() const
{
	return "JAIL";
}
