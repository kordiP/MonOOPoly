#pragma once
#include "Command.h"
#include "../Entities/Fields/Field.h"
#include "../Entities/Fields/JailField.h"

class RollDice : public Command
{
public:
    RollDice() = default;
    void execute() const override;
};