#pragma once
#include "Mortgage.h"

class Castle : public Mortgage
{
public:
	Castle();
	double getRentIncrease() const override;
	Mortgage* clone() const override;
	void saveToFile(std::ofstream& ofs) const override;
};