#include "../../../Headers/Entities/Mortgages/Cottage.h"

Cottage::Cottage()
{
    increaseMultipl = 1.15;
}

double Cottage::getRentIncrease() const
{
    return increaseMultipl;
}

Mortgage* Cottage::clone() const
{
    return new Cottage(*this);
}

void Cottage::saveToFile(std::ofstream& ofs) const
{
    const char* type = "Cottage";
    int length = strlen(type);
    ofs.write(reinterpret_cast<const char*>(&length), sizeof(length));
    ofs.write(type, length);
}
