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
	const char* type = "CarPark";
	int length = strlen(type);
	ofs.write(reinterpret_cast<const char*>(&length), sizeof(length));
	ofs.write(type, length);

	int index = getFieldIndex();
	ofs.write(reinterpret_cast<const char*>(index), sizeof(index));
}

MyString CarPark::getPrintInfo() const
{
    return "PARK";
}
