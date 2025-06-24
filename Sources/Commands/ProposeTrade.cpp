#include "../../Headers/Commands/ProposeTrade.h"

void ProposeTrade::execute() const
{
	if (!data.isGameStarted())
	{
		throw std::logic_error("Game not started.");
	}

	Player& curPl = data.getCurrentPlayer();

	int fieldIndex, requestedAmount;
	MyString description, receiverName;

	std::cout << "Write the owner and the index of the property with the amount you want to pay: " << std::endl;
	std::cout << "Owner: ";
	std::cin >> receiverName;
	std::cout << "Field: ";
	std::cin >> fieldIndex;
	std::cout << "Amount you want: ";
	std::cin >> requestedAmount;
	std::cout << "A message to the receiver: ";
	std::cin >> description;

	Player& receiver = data.getPlayer(receiverName);

	if (fieldIndex < 0 || fieldIndex > 32 || fieldIndex % 4 == 0)
	{
		throw std::invalid_argument("Invalid field");
	}

	if (curPl.getName() == receiver.getName())
	{
		throw std::invalid_argument("Cannot send offers to yourself.");
	}

	if (!data.getProperty(fieldIndex).isOwner(receiver))
	{
		throw std::invalid_argument("This field does not belong to the player.");
	}

	Trade trade(&curPl, &receiver, description, fieldIndex, requestedAmount);
	data.proposeTrade(trade);

	data.clearBoard();
	data.printBoard();
}
