#include "../../../Headers/Entities/Fields/Property.h"

Property::Property(int index, const MyString& descr, int color, int baseRent, int basePur, int cottageBuild, int castleBuild) : Field(index, descr, color)
{
	this->baseRent = baseRent;
	basePurchase = basePur;
	cottageBuildPrice = cottageBuild;
	castleBuildPrice = castleBuild;
}

bool Property::hasMortgage() const
{
	return mortgage == nullptr;
}

const Mortgage* Property::getMortgage() const
{
	return mortgage;
}

int Property::getRent() const
{
	return baseRent;
}

int Property::getPurchasePrice() const
{
	return basePurchase;
}

int Property::getCottageBuildPrice() const
{
	return cottageBuildPrice;
}

int Property::getCastleBuildPrice() const
{
	return castleBuildPrice;
}

void Property::setOwner(Player& player)
{
	owner = &player;
}

void Property::removeOwner()
{
	owner = nullptr;
}
void Property::buyMortgage(Mortgage& mort)
{
	if (dynamic_cast<Castle*>(&mort))
	{
		owner->buyCastle(getFieldIndex());
	}
	else if (dynamic_cast<Cottage*>(&mort))
	{
		owner->buyCottage(getFieldIndex());
	}
}

void Property::removeMortgage()
{
	mortgage = nullptr;
}

Field* Property::clone() const
{
	return new Property(*this);
}

void Property::steppedOnBy(Player& player)
{
}

void Property::print() const
{
}

void Property::printDescription() const
{
}

void Property::saveToFile(std::ofstream& ofs) const
{
}
