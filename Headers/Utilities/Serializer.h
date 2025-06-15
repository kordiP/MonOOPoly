#pragma once
#include "../Utilities/MyString.h"

namespace 
{
	const MyString BOARD_LOCATION = "board.dll";
	const MyString PLAYERS_LOCATION = "players.dll";
}

/*
	What is the file/files going to contain?
	1. Board with all fields /duh/
	2. All field's properties and who they belong to
	3. All of the players' positions
	4. The current player / thy one to roll
	5. All info for player - money, position
	6. Mortgages that a player has
	7. The card deck
	8. The bank does not need to be saved, it just controls the money flow
	9. 
*/

class Serializer
{
private:
	void readBoard();
	void readPlayers();

public:
	void createGameSave();
	void readGameSave();
};