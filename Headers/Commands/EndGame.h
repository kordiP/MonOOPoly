#pragma once
#include "Command.h"

class EndGame : public Command
{
public:
    EndGame() = default;
    void execute() const override;
};