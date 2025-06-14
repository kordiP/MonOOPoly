#pragma once
#include "Field.h"
#include "../Player.h"
#include "../Mortgages/Mortgage.h"

class Property : public Field
{
private:
	Player* owne = nullptr;
	Mortgage* mortgage = nullptr;
	MyString color;

	int baseRent;
	int basePurchase;

	int cottageBuildPrice;
	int castleBuildPrice;

public:
	Property();
	Property(int indexOnBoard, const MyString& description, const MyString& color, int baseRent, int basePurchase, int cottageBuildPrice, int castleBuildPrice);

	Field* clone() const override;

	bool hasMortgage() const;
	const Mortgage* getMortgage() const;
	const MyString& getColor() const;
	int getRent() const;
	int getPurchasePrice() const;
	int getCottageBuildPrice() const;
	int getCastleBuildPrice() const;

	void setOwner(Player* player);
	void removeOwner();

	void removeMortgage();
	void addMortgage(const Mortgage& mortgage);

	void steppedOnBy(Player* player) override;

	void print() const override;
	void printDescription() const override;

	void saveToFile(std::ofstream& ofs) const override;
};