#pragma once
#include "../Bank.h"
#include "../../Utilities/Colors.h"

class Field
{
private:
	int indexOnBoard = -1;
	int color = -1;
	MyString description;
public:
	Field() = default;
	Field(int index, const MyString& descr, int color = Colors::DEFAULT_COLOR);
	virtual ~Field() = default;
	virtual Field* clone() const = 0;

	int getFieldIndex() const;
	int getColor() const;
	virtual void steppedOnBy(Player& player) = 0;
	virtual void print() const = 0;
	virtual void printDescription() const = 0;

	virtual void saveToFile(std::ofstream& ofs) const = 0;
};