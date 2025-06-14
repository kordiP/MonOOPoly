#pragma once

class Command
{
public:
	virtual void execute() const = 0;
	virtual ~Command() = default;
};
