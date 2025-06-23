#include "../../../Headers/Entities/Fields/CarPark.h"

CarPark::CarPark(int index, const MyString& descr) : Field(index, descr) { }

Field* CarPark::clone() const
{
    return new CarPark(*this);
}

void CarPark::steppedOnBy(Player& player)
{
    player.moveBy(0);
}

void CarPark::saveToFile(std::ofstream& ofs) const
{
    // todo
}
