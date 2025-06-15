#pragma once
#include "Command.h"
#include <iostream>
#include "../Utilities/Serializer.h"

class StartNewGame : public Command 
{
public:
    StartNewGame() = default;
    void execute() const override;
};