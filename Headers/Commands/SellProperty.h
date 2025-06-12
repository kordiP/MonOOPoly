#pragma once
#include "Command.h"

class SellProperty : public Command
{
public:
    SellProperty() = default;
    void execute() const override;
};