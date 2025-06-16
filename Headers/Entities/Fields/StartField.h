#pragma once
#include "Field.h"

class StartField : public Field
{
private:
	double rewardForPlayer = 200;
public:
	StartField() = default;
	StartField(int index, const MyString& content);

	Field* clone() const override;
	void steppedOnBy(Player& player) override;
	void saveToFile(std::ofstream& ofs) const override;
};