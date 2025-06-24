#pragma once
#include "../Utilities/MyString.h"

namespace 
{
	const MyString BOARD_LOCATION = "board.dll";
	const MyString PLAYERS_LOCATION = "players.dll";
	const MyString TRADES_LOCATION = "trades.dll";
	const MyString MORTGAGES_LOCATION = "mortgages.dll";
}

class Serializer
{
private:
	Serializer() = default;
	~Serializer() = default;

	Serializer(const Serializer&) = delete;
	Serializer& operator=(const Serializer&) = delete;
	Serializer(Serializer&&) = delete;
	Serializer& operator=(Serializer&&) = delete;

	void readBoard();
	void readPlayers();

public:
	static Serializer& getInstance();
	void createGameSave();
	void readGameSave();
};