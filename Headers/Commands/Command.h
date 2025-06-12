#pragma once
#include "../Entities/Board.h"
#include "../Entities/Bank.h"

class Command
{
protected:
	Board* board;
	Bank* bank;
public:
	virtual void execute() const = 0;
	virtual ~Command() = default;
};
