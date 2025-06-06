#include "../Headers/MonopolyEngine.h"

MonopolyEngine& MonopolyEngine::getInstance()
{
    static MonopolyEngine instance;
    return instance;
}

void MonopolyEngine::run()
{

}