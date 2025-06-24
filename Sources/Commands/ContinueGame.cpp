#include "../../Headers/Commands/ContinueGame.h"

void ContinueGame::execute() const
{
	Serializer& s = Serializer::getInstance();

	s.readGameSave();
	size_t cardDeckSize = data.getCurrentPlayersCount() * 6;
	data.generateRandomDeck(cardDeckSize);
}
