#include "../../../Headers/Entities/Fields/StartField.h"

StartField::StartField(int index, const MyString& content) : Field(index, content) { }

Field* StartField::clone() const
{
    return new StartField(*this);
}

void StartField::steppedOnBy(Player& player)
{
    std::cout << "Way to GO! Here's " << rewardForPlayer << std::endl;
    player.increaseBalance(rewardForPlayer);
}

void StartField::saveToFile(std::ofstream& ofs) const
{
    const char* type = "StartField";
    int length = strlen(type);
    ofs.write(reinterpret_cast<const char*>(&length), sizeof(length));
    ofs.write(type, length);

    int index = getFieldIndex();
    ofs.write(reinterpret_cast<const char*>(&index), sizeof(index));
    ofs.write(reinterpret_cast<const char*>(&rewardForPlayer), sizeof(rewardForPlayer));
}

MyString StartField::getPrintInfo() const
{
    return " GO ";
}
