#pragma once
#include "Command.h"
#include "../Utilities/MyString.h"

class StartGame : public Command 
{
private:
    

public:
    StartGame(size_t playerNumber) 
    {

    }
    void execute() const override 
    {
        std::cout << "";
    }
};