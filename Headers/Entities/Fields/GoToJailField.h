#pragma once
#include "Field.h"

class GoToJailField : public Field
{
private:
	int jailFieldIndex = -1;
public:
	GoToJailField() = default;
	GoToJailField(int index, const MyString& descr, int jailIndex);

	Field* clone() const override;
	void steppedOnBy(Player& player) override;
	void saveToFile(std::ofstream& ofs) const override;
};