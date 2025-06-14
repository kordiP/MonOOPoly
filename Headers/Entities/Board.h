#pragma once
#include "../Utilities/HeterogenousContainer.hpp"
#include "../Entities/Fields/Field.h"

class Board
{
private:
    HeterogeneousContainer<Field> fields;

    Board();
    ~Board() = default;

    Board(const Board&) = delete;
    Board& operator=(const Board&) = delete;
    Board(Board&&) = delete;
    Board& operator=(Board&&) = delete;
public:
    static Board& getInstance();
    
    void printBoard() const;
};