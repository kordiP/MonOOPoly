#pragma once
#include "Field.h"

class CarPark : public Field
{
public:
	CarPark();
	CarPark(int index, const MyString& descr);

	Field* clone() const override;
	void steppedOnBy(Player& player) override;
	void print() const override;
	void printDescription() const override;
	void saveToFile(std::ofstream& ofs) const override;
};