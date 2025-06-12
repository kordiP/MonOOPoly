#pragma once
#include "Command.h"

class AcceptTrade : public Command
{
public:
    AcceptTrade() = default;
    void execute() const override;
};