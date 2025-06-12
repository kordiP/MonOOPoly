#pragma once
#include "Command.h"

class SetMortgage : public Command
{
public:
    SetMortgage() = default;
    void execute() const override;
};
