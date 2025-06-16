#pragma once
#include <fstream>

class Mortgage
{
protected:
	double increaseMultipl = 0;
public:
	virtual ~Mortgage() = default;

	virtual double getRentIncrease() const = 0;
	virtual Mortgage* clone() const = 0;
	virtual void saveToFile(std::ofstream& ofs) const = 0;
};