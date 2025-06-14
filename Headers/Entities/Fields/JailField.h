#pragma once
#include "Field.h"

class JailField : public Field
{
private:
	int feeForEscape;
public:
	JailField();
	JailField(int index, const MyString& content, int feeForEscape);

	int getFeeForEscape();

	Field* clone() const override;
	void steppedOnBy(Player* player) override;
	void print() const override;
	void printDescription() const override;
	void saveToFile(std::ofstream& ofs) const override;
};