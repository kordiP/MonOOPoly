#pragma once
#include "../GameLogic.h"
#include "Command.h"

class StartGame : public Command 
{
private:
    GameLogic* logic;
public:
    explicit StartGame(GameLogic* log);
    ~StartGame();
    void execute() const override;
};