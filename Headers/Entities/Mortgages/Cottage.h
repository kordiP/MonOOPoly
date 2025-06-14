#pragma once
#include "Mortgage.h"

class Cottage : public Mortgage
{
public:
	Cottage(); // mult = 0.15
	double getRentIncrease() const override;
	Mortgage* clone() const override;
	void saveToFile(std::ofstream& ofs) const override;
};