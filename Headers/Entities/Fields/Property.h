#pragma once
#include "Field.h"
#include "../Player.h"
#include "../Mortgages/Mortgage.h"
#include "../Mortgages/Castle.h"
#include "../Mortgages/Cottage.h"

class Property : public Field
{
private:
	Player* owner = nullptr;
	Mortgage* mortgage = nullptr;

	int baseRent;
	int basePurchase;

	int cottageBuildPrice;
	int castleBuildPrice;

public:
	Property() = default;
	Property(int index, const MyString& descr, int color, int baseRent, int basePur, int cottageBuild, int castleBuild);

	bool hasMortgage() const;
	const Mortgage* getMortgage() const;
	const MyString& getColor() const;
	int getRent() const;
	int getPurchasePrice() const;
	int getCottageBuildPrice() const;
	int getCastleBuildPrice() const;

	void setOwner(Player& player);
	void removeOwner();

	void buyMortgage(Mortgage& mort);
	void removeMortgage();
	bool isOwner(Player& player);

	Field* clone() const override;
	void steppedOnBy(Player& player) override;
	void saveToFile(std::ofstream& ofs) const override;
};