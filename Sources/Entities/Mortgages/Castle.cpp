#include "../../../Headers/Entities/Mortgages/Castle.h"

Castle::Castle()
{
	increaseMultipl = 1.5;
}

double Castle::getRentIncrease() const
{
	return 0.0;
}

Mortgage* Castle::clone() const
{
	return nullptr;
}

void Castle::saveToFile(std::ofstream& ofs) const
{
}
