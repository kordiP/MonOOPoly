#pragma once
#include "Command.h"
#include "../Entities/Fields/Field.h"
#include "../Entities/Fields/Property.h"
#include "../Entities/Mortgages/Mortgage.h"
#include "../Entities/Mortgages/Cottage.h"
#include "../Entities/Mortgages/Castle.h"

class SetMortgage : public Command
{
public:
    SetMortgage() = default;
    void execute() const override;
};
