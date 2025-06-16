#include "../../../Headers/Entities/Fields/CarPark.h"

CarPark::CarPark()
{
}

CarPark::CarPark(int index, const MyString& descr) : Field(index, descr)
{
}

Field* CarPark::clone() const
{
    return nullptr;
}

void CarPark::steppedOnBy(Player& player)
{
}

void CarPark::print() const
{
}

void CarPark::printDescription() const
{
}

void CarPark::saveToFile(std::ofstream& ofs) const
{
}
