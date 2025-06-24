#pragma once
#include "Command.h"
#include "../Utilities/Serializer.h"

class ContinueGame : public Command
{
private:
public:
    ContinueGame() = default;
    void execute() const override;
};