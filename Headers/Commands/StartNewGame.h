#pragma once
#include "Command.h"

class StartNewGame : public Command 
{
public:
    StartNewGame() = default;
    void execute() const override;
};