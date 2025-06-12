#pragma once
#include "Command.h"

class BuyProperty : public Command
{
public:
    BuyProperty() = default;
    void execute() const override;
};