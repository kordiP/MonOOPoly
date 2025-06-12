#pragma once
#include "Command.h"

class ContinueGame : public Command
{
private:
public:
    ContinueGame() = default;
    void execute() const override;
};