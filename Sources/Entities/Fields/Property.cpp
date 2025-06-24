#include "../../../Headers/Entities/Fields/Property.h"

Property::Property(int index, const MyString& descr, int color, int baseRent, int basePur, int cottageBuild, int castleBuild) : Field(index, descr, color)
{
	this->baseRent = baseRent;
	basePurchase = basePur;
	cottageBuildPrice = cottageBuild;
	castleBuildPrice = castleBuild;
}

Property::~Property()
{
	owner = nullptr;
	mortgage = nullptr;
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

const Player* Property::getOwner() const
{
	return owner;
}

void Property::removeOwner()
{
	owner = nullptr;
}
void Property::buyMortgage(Mortgage& mort)
{
	if (dynamic_cast<Castle*>(&mort))
	{
		owner->decreaseBalance(castleBuildPrice);
	}
	else if (dynamic_cast<Cottage*>(&mort))
	{
		owner->decreaseBalance(cottageBuildPrice);
	}
}

void Property::removeMortgage()
{
	mortgage = nullptr;
}

bool Property::isOwner(Player& player)
{
	return owner->getName() == player.getName();
}

Field* Property::clone() const
{
	return new Property(*this);
}

void Property::steppedOnBy(Player& player)
{
	std::cout << "Description: " << getDescription() << std::endl;
	if (owner == nullptr)
	{
		std::cout << "This property is unoccupied yet. Type \"Buy\" to buy it for " << basePurchase << std::endl;
		MyString resp;
		std::cin >> resp;

		if (resp == "Buy")
		{
			player.decreaseBalance(basePurchase);
			owner = &player;
		}
	}
	else if (owner != nullptr)
	{
		double finalAmount = baseRent;
		if (mortgage != nullptr)
		{
			finalAmount *= mortgage->getRentIncrease();
		}
		std::cout << "You stepped on another player's property, the rent is " << finalAmount << std::endl;
		player.decreaseBalance(finalAmount);
		owner->increaseBalance(finalAmount);
	}
}

void Property::saveToFile(std::ofstream& ofs) const
{
	// todo
}

MyString Property::getPrintInfo() const
{
	MyString res;
	int emptyCnt = 0;
	res += getFieldIndex();

	if (mortgage != nullptr)
	{
		if (dynamic_cast<Castle*>(mortgage)) res += '^';
		else res += '=';

		if (getFieldIndex() < 10) emptyCnt = 2;
		else emptyCnt = 1;
	}
	else
	{
		if (getFieldIndex() < 10) emptyCnt = 3;
		else emptyCnt = 2;
	}

	for (size_t i = 0; i < emptyCnt; i++) res += ' ';

	return res;
}
