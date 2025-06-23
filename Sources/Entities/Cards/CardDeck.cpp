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

		switch (num)
		{
		case 1:
			card = new GroupPaymentCard();
			deck.push(*card);
			break;
		case 2:
			card = new PaymentCard();
			deck.push(*card);
			break;
		case 3:
			card = new MovePositionCard();
			deck.push(*card);
			break;
		}
	}
}

void CardDeck::drawCard(Player& player)
{
	deck.popToBottom()->applyEffectTo(player);
}
