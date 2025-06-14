#pragma once
#include "../Utilities/HeterogenousContainer.hpp"
#include "../Entities/Fields/Field.h"

class Board
{
private:
    bool isGameOver = false;

    HeterogeneousContainer<Field> fields;
	MyVector<Player> players;

    Board();
    ~Board() = default;

    Board(const Board&) = delete;
    Board& operator=(const Board&) = delete;
    Board(Board&&) = delete;
    Board& operator=(Board&&) = delete;
public:
    static Board& getInstance();
    
    void printBoard() const;

	bool isGameOver() const;
	int getCurrentPlayersCount() const;

	int getCurrentPlayerIndex() const;
	Player* getPlayer(int index);
	void addPlayer(const Player& player);

	int getBoardSize() const;
	Field* getField(int index);
	int getJailIndex() const;

	void printBoard() const;
	void playTurn(int playerIndex);
	void playTurn();

};