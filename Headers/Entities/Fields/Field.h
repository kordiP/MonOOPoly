#pragma once
#include "../Bank.h"

class Field
{
private:
	int indexOnBoard;
	MyString description;
public:
	Field();
	Field(int index, const MyString& descr);
	virtual ~Field() = default;
	virtual Field* clone() const = 0;

	int getFieldIndex() const;
	virtual void steppedOnBy(Player* player) = 0;
	virtual void print() const = 0;
	virtual void printDescription() const = 0;

	virtual void saveToFile(std::ofstream& ofs) const = 0;
};