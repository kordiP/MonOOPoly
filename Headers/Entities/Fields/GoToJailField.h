#pragma once
#include "Field.h"

class GoToJailField : public Field
{
private:
	int jailFieldIndex;

public:
	GoToJailField();
	GoToJailField(int index, const MyString& descr, int jailIndex);

	Field* clone() const override;
	void steppedOnBy(Player* player) override;
	void print() const override;
	void printDescription() const override;
	void saveToFile(std::ofstream& ofs) const override;
};