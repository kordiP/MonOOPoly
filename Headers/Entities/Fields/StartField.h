#pragma once
#include "Field.h"

class StartField : public Field
{
private:
	double rewardForPlayer = 200;
public:
	StartField();
	StartField(int index, const MyString& content);

	Field* clone() const override;
	void steppedOnBy(Player* player) override;
	void print() const override;
	void printDescription() const override;
	void saveToFile(std::ofstream& ofs) const override;
};