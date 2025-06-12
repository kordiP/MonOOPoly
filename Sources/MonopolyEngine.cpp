#include "../Headers/MonopolyEngine.h"

void MonopolyEngine::printWelcomeScreen() const
{
    
}

MonopolyEngine& MonopolyEngine::getInstance()
{
    static MonopolyEngine instance;
    return instance;
}

void MonopolyEngine::run()
{
    MyString input;
}