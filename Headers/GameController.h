#pragma once
#include "../Headers/Commands/Command.h"

// command invoker
class GameController
{
private:
	Command* command;
public:
	GameController();
	~GameController();

	void setCommand(Command* com);

	void startGame();
};