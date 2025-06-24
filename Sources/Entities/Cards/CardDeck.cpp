#include "../../../Headers/Entities/Cards/CardDeck.h"

CardDeck& CardDeck::getInstance()
{
	static CardDeck deck;
	return deck;
}

void CardDeck::generateRandomDeck(size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		Card* card;
		size_t num = rand() % 3 + 1;

		int amountRnd = rand() % 200 + 100;
		int moveRnd = rand() % 10 - 5;

		switch (num)
		{
		case 1:
			card = new GroupPaymentCard(amountRnd);
			deck.push(*card);
			break;
		case 2:
			card = new PaymentCard(amountRnd);
			deck.push(*card);
			break;
		case 3:
			card = new MovePositionCard(moveRnd);
			deck.push(*card);
			break;
		}
	}
}

void CardDeck::drawCard(Player& player)
{
	Card* c = deck.popToBottom();
	c->printCardInfo();
	MyString wait;
	std::cout << "Press enter to continue." << std::endl;
	std::cin >> wait;
	c->applyEffectTo(player);
}
