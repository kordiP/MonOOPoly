#pragma once
#include "../Bank.h"

class Field
{
private:
	int indexOnBoard;
	int color;
	MyString description;
public:
	Field();
	Field(int index, const MyString& descr, int color);
	virtual ~Field() = default;
	virtual Field* clone() const = 0;

	int getFieldIndex() const;
	int getColor() const;
	virtual void steppedOnBy(Player& player) = 0;
	virtual void print() const = 0;
	virtual void printDescription() const = 0;

	virtual void saveToFile(std::ofstream& ofs) const = 0;
};