#pragma once
#include "Command.h"

class WelcomeScreen : public Command
{
public:
    WelcomeScreen() = default;
    void execute() const override;
};