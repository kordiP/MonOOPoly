#pragma once
#include "Command.h"

class RollDice : public Command
{
public:
    RollDice() = default;
    void execute() const override;
};