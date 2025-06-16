#include "../../Headers/Commands/SetMortgage.h"

void SetMortgage::execute() const
{
	if (data.getCurrentPlayerIndex() == -1)
	{
		throw std::logic_error("Game not started.");
	}

	Player& curPl = data.getCurrentPlayer();

	std::cout << "Write which field the mortgage would be at: ";
	int fieldAt;
	std::cin >> fieldAt;

	if (!data.isEligibleForMortgage(fieldAt))
	{
		throw std::invalid_argument("This building is not eligible for a mortgage.");
	}

	std::cout << "Type \"Cottage\" or \"Castle\" to select option: ";
	MyString mortgType;
	std::cin >> mortgType;

	Property& prop = dynamic_cast<Property&>(*data.getFieldAt(fieldAt));

	if (mortgType == "Cottage")
	{
		if (curPl.getBalance() < prop.getCottageBuildPrice())
		{
			throw std::invalid_argument("You cannot afford that.");
		}
		if (prop.getMortgage() != nullptr)
		{
			throw std::invalid_argument("You cannot stack the same type of mortgage on a building.");
		}

		Cottage c;
		prop.buyMortgage(c);
	}
	else if (mortgType == "Castle")
	{
		if (curPl.getBalance() < prop.getCastleBuildPrice())
		{
			throw std::invalid_argument("You cannot afford that.");
		}
		if (!dynamic_cast<const Castle*>(prop.getMortgage()))
		{
			throw std::invalid_argument("Castle already bought.");
		}
		if (!dynamic_cast<const Cottage*>(prop.getMortgage()))
		{
			throw std::invalid_argument("You need to buy a cottage first.");
		}

		Castle c;
		prop.buyMortgage(c);
	}
	else
	{
		throw std::invalid_argument("Invalid mortgage type.");
	}

	data.printBoard();
}
