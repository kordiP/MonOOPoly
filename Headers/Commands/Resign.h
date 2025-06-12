#pragma once
#include "Command.h"

// both self-resign or inevitable bankrupcy
class Resign : public Command
{
public:
    Resign() = default;
    void execute() const override;
};