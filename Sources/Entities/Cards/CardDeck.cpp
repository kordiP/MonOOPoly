#include "../../../Headers/Entities/Cards/CardDeck.h"

void CardDeck::generateRandomDeck(size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		size_t num = rand() % 3 + 1;

		switch (num)
		{
		case 1:
			Card* g = new GroupPaymentCard();
			deck.push(*g);
		case 2:
			Card* g = new PaymentCard();
			deck.push(*g);
		case 3:
			Card* g = new MovePositionCard();
			deck.push(*g);
		}
	}
}

void CardDeck::drawCard(Player& player)
{
	deck.top().applyEffectTo(player);
	deck.popToBottom();
}
