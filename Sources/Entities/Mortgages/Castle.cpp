#include "../../../Headers/Entities/Mortgages/Castle.h"

Castle::Castle()
{
	increaseMultipl = 1.5;
}

double Castle::getRentIncrease() const
{
	return increaseMultipl;
}

Mortgage* Castle::clone() const
{
	return new Castle(*this);
}

void Castle::saveToFile(std::ofstream& ofs) const
{
}
