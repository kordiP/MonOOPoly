#pragma once
#include "Command.h"

class HelpMenu : public Command
{
public:
    HelpMenu() = default;
    void execute() const override;
};