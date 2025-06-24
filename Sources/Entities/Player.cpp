#include "../../Headers/Entities/Player.h"

Player::Player(const MyString& playerName, char fig)
{
	name = playerName;
	figure = fig;
}

const MyString& Player::getName() const
{
	return name;
}

int Player::getConsecPairsCount() const
{
	return consecPairs;
}

void Player::pairThrown()
{
	consecPairs++;
}

char Player::getFigure() const
{
	return figure;
}

int Player::getPositionIndex() const
{
	return currentPostionIndex;
}

void Player::resign()
{
	isInGame = false;
}

bool Player::isResigned() const
{
	return !isInGame;
}

bool Player::toSkipTurn() const
{
	return hasToSkip;
}

void Player::resetPairCount()
{
	consecPairs = 0;
}

void Player::shouldSkipTurn(bool skip)
{
	hasToSkip = skip;
}

bool Player::hasEnoughBalance(int debt) const
{
	return balance >= debt;
}

bool Player::hasEnoughAssets(int debt) const
{
	return balance >= debt;
}

void Player::moveBy(int count)
{
	currentPostionIndex += count;

	if (currentPostionIndex >= 32)
	{
		currentPostionIndex -= 32;
	}
}

void Player::moveTo(int fieldIndex)
{
	currentPostionIndex = fieldIndex;

	if (currentPostionIndex >= 32)
	{
		currentPostionIndex -= 32;
	}
}

double Player::getBalance() const
{
	return balance;
}

void Player::increaseBalance(int amount)
{
	balance += amount;
}

void Player::decreaseBalance(int amount)
{
	balance -= amount;
}

void Player::saveToFile(std::ofstream& ofs) const
{
	int length = strlen(name.c_str());
	ofs.write(reinterpret_cast<const char*>(&length), sizeof(length));
	ofs.write(name.c_str(), length);

	ofs.write(reinterpret_cast<const char*>(&isInGame), sizeof(isInGame));
	ofs.write(reinterpret_cast<const char*>(&hasToSkip), sizeof(hasToSkip));
	ofs.write(reinterpret_cast<const char*>(&balance), sizeof(balance));
	ofs.write(reinterpret_cast<const char*>(&consecPairs), sizeof(consecPairs));
	ofs.write(reinterpret_cast<const char*>(&currentPostionIndex), sizeof(currentPostionIndex));	
}
