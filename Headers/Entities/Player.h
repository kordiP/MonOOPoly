#pragma once
#include "../Utilities/MyString.h"
#include <fstream>

class Player
{
private:
	bool isInGame = true;
	bool hasToSkip = false;
	int consecPairs = 0;

	MyString name;
	char figure = 0;
	size_t currentPostionIndex = 0;
	double balance = 1500;
public:
	Player() = default;
	Player(const MyString& playerName, char fig);

	const MyString& getName() const;
	int getConsecPairsCount() const;
	void pairThrown();
	char getFigure() const;
	int getPositionIndex() const;

	void resign();
	bool isResigned() const;
	bool toSkipTurn() const;
	void resetPairCount();

	void shouldSkipTurn(bool skip);

	bool hasEnoughBalance(int debt) const;
	bool hasEnoughAssets(int debt) const;

	void moveBy(int count);
	void moveTo(int fieldIndex);

	double getBalance() const;
	void increaseBalance(int amount);
	void decreaseBalance(int amount);

	void saveToFile(std::ofstream& ofs) const;
};