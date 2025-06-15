#include "../../Headers/Entities/Player.h"

Player::Player()
{
}

Player::Player(const MyString& playerName)
{
}

const MyString& Player::getName() const
{
	return name;
}

int Player::getConsecPairsCount() const
{
	return 0;
}

void Player::pairThrown()
{
}

int Player::getPositionIndex() const
{
	return 0;
}

void Player::resign()
{
}

bool Player::isResigned() const
{
	return false;
}

bool Player::toSkipTurn() const
{
	return false;
}

void Player::resetPairCount()
{
}

bool Player::hasToSkipTurn()
{
	return false;
}

void Player::shouldSkipTurn(bool skip)
{
}

bool Player::hasEnoughBalance(int debt) const
{
	return false;
}

bool Player::hasEnoughAssets(int debt) const
{
	return false;
}

bool Player::inDebtFrom(int fieldIndex) const
{
	return false;
}

void Player::moveBy(int count)
{
}

void Player::moveTo(int fieldIndex)
{
}

void Player::increaseBalance(int amount)
{
}

void Player::decreaseBalance(int amount)
{
}

void Player::buyCastle(int fieldIndex)
{
}

void Player::buyCottage(int fieldIndex)
{
}

void Player::sellProperty(int fieldIndex)
{
}

void Player::saveToFile(std::ofstream& ofs) const
{
}
