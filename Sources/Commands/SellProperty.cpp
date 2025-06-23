#include "../../Headers/Commands/SellProperty.h"

void SellProperty::execute() const
{
	if (data.getCurrentPlayerIndex() == -1)
	{
		throw std::logic_error("Game not started.");
	}

	data.clearBoard();

	Player& curPl = data.getCurrentPlayer();

	std::cout << "Please enter the index of the field you want to sell: ";
	int fieldIndex;
	std::cin >> fieldIndex;
	Property& pr = data.getProperty(fieldIndex);
	
	if (!pr.isOwner(curPl))
	{
		throw std::invalid_argument("This property is not yours.");
	}

	pr.removeOwner();

	if (pr.hasMortgage())
	{
		int neighbourPos = pr.getFieldIndex() % 4;
		pr.removeMortgage();

		Property& n1 = data.getProperty(fieldIndex + 1);
		Property& n2 = data.getProperty(fieldIndex + 2);

		switch (neighbourPos)
		{
		case 1:
			n1 = data.getProperty(fieldIndex + 1);
			n2 = data.getProperty(fieldIndex + 2);
			break;
		case 2:
			n1 = data.getProperty(fieldIndex + 1);
			n2 = data.getProperty(fieldIndex - 1);
			break;
		case 3:
			n1 = data.getProperty(fieldIndex - 1);
			n2 = data.getProperty(fieldIndex - 2);
			break;
		default:
			throw std::logic_error("Something went wrong in calculating neighbours' positions.");
			break;
		}

		n1.removeMortgage();
		n2.removeMortgage();
	}

	data.printBoard();
}
