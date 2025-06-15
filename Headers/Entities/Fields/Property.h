#pragma once
#include "Field.h"
#include "../Player.h"
#include "../Mortgages/Mortgage.h"

class Property : public Field
{
private:
	Player* owner = nullptr;
	Mortgage* mortgage = nullptr;
	MyString color;

	int baseRent;
	int basePurchase;

	int cottageBuildPrice;
	int castleBuildPrice;

public:
	Property();
	Property(int index, const MyString& descr, const MyString& color, int baseRent, int basePur, int cottageBuild, int castleBuild);

	bool hasMortgage() const;
	const Mortgage* getMortgage() const;
	const MyString& getColor() const;
	int getRent() const;
	int getPurchasePrice() const;
	int getCottageBuildPrice() const;
	int getCastleBuildPrice() const;

	void setOwner(Player* player);
	void removeOwner();

	void buyMortgage(Mortgage* mortgage);
	void removeMortgage(); // if building is sold / any of the buildings from this one's color -> remove das mortgaj

	Field* clone() const override;
	void steppedOnBy(Player& player) override;
	void print() const override;
	void printDescription() const override;
	void saveToFile(std::ofstream& ofs) const override;
};