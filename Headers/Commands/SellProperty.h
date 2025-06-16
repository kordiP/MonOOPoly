#pragma once
#include "Command.h"
#include "../Entities/Fields/Property.h"

class SellProperty : public Command
{
public:
    SellProperty() = default;
    void execute() const override;
};