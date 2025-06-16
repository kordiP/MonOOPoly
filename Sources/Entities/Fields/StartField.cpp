#include "../../../Headers/Entities/Fields/StartField.h"

StartField::StartField(int index, const MyString& content) : Field(index, content, 0)
{
}

Field* StartField::clone() const
{
    return new StartField(*this);
}

void StartField::steppedOnBy(Player& player)
{
    player.increaseBalance(rewardForPlayer);
}

void StartField::saveToFile(std::ofstream& ofs) const
{
}
