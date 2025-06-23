#include "../../Headers/Commands/ProposeTrade.h"

void ProposeTrade::execute() const
{
	if (data.getCurrentPlayerIndex() == -1)
	{
		throw std::logic_error("Game not started.");
	}

	data.clearBoard();

	Player& curPl = data.getCurrentPlayer();

	int fieldIndex, requestedAmount;
	MyString description, receiverName;

	std::cout << "Write the owner and the index of the property with the amount you want: " << std::endl;
	std::cout << "Owner: ";
	std::cin >> receiverName;
	std::cout << "Field: ";
	std::cin >> fieldIndex;
	std::cout << "Amount you want: ";
	std::cin >> requestedAmount;
	std::cout << "A message to the receiver: ";
	std::cin >> description;

	Player& receiver = data.getPlayer(receiverName);

	if (curPl.getName() == receiver.getName())
	{
		throw std::invalid_argument("Cannot send offers to yourself.");
	}

	Trade trade(&curPl, &receiver, description, fieldIndex, requestedAmount);
	data.proposeTrade(trade);
	data.printBoard();
}
