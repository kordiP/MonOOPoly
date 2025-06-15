#pragma once
#include "../GameData.h"

class Command
{
protected:
	GameData& data;
public:
	Command();
	virtual void execute() const = 0;
	virtual ~Command() = default;
};
