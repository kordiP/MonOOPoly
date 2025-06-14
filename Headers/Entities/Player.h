#pragma once
#include "../Utilities/MyString.h"
#include <fstream>

class Player
{
private:
	bool resigned = false;
	int consecPairs = 0;

	MyString name;
	size_t currentPostionIndex = 0;
	double balance;
public:
	Player();
	Player(int playerIndex, const MyString& playerName, const MyString& color, int playerBalance);

	const MyString& getName() const;
	int getConsecPairsCount() const;
	int getPositionIndex() const;

	void resign();
	bool isResigned() const;
	bool toSkipTurn() const;

	bool hasEnoughBalance(int debt) const;
	// balance + sell price of all their properties
	bool hasEnoughAssets(int debt) const;
	bool inDebtFrom(int fieldIndex) const;

	void moveBy(int count);
	void moveTo(int fieldIndex);

	void increaseBalance(int amount);
	void decreaseBalance(int amount);

	void buyCastle(int fieldIndex);
	void buyCottage(int fieldIndex);
	void sellProperty(int fieldIndex);

	void saveToFile(std::ofstream& ofs) const;
};