#pragma once
#include "Command.h"
#include <iostream>

class WelcomeScreen : public Command
{
public:
    WelcomeScreen() = default;
    void execute() const override;
};