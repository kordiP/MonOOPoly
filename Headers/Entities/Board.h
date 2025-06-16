#pragma once
#include "../Utilities/HeterogenousContainer.hpp"
#include "../Entities/Fields/Field.h"
#include "../Entities/Fields/JailField.h"
#include "../Entities/Fields/CardField.h"
#include "../Entities/Fields/CarPark.h"
#include "../Entities/Fields/GoToJailField.h"
#include "../Entities/Fields/Property.h"
#include "../Entities/Fields/StartField.h"

class Board
{
private:
    HeterogeneousContainer<Field> fields;

    Board() = default;
    ~Board() = default;

    Board(const Board&) = delete;
    Board& operator=(const Board&) = delete;
    Board(Board&&) = delete;
    Board& operator=(Board&&) = delete;
public:
    static Board& getInstance();

    void generate();
    
	int getBoardSize() const;
    int getJailTax() const;
	Field* getField(int index);
    const Field* getField(int index) const;
	int getJailIndex() const;

	void printBoard() const;
};