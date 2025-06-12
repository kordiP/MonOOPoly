#pragma once
#include "Command.h"

class ProposeTrade : public Command
{
public:
    ProposeTrade() = default;
    void execute() const override;
};