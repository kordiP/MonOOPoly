#pragma once

#pragma once
#include "Command.h"

class ViewTrades : public Command
{
public:
    ViewTrades() = default;
    void execute() const override;
};