#pragma once
#include "Field.h"

class JailField : public Field
{
private:
	int feeForEscape;
public:
	JailField() = default;
	JailField(int index, const MyString& content, int feeForEscape);

	int getFeeForEscape() const;

	Field* clone() const override;
	void steppedOnBy(Player& player) override;
	void saveToFile(std::ofstream& ofs) const override;
	MyString getPrintInfo() const override;
};