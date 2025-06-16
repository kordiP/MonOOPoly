#pragma once
#include "Field.h"

class CarPark : public Field
{
public:
	CarPark() = default;
	CarPark(int index, const MyString& descr);

	Field* clone() const override;
	void steppedOnBy(Player& player) override;
	void saveToFile(std::ofstream& ofs) const override;
};