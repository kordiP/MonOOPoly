#pragma once
#include <iostream>
#include "../Headers/Utilities/MyString.h"
#include "../Headers/Commands/CommandInterpretor.h"
#include "GameData.h"

class MonopolyEngine
{
private:
    GameData& data = GameData::getInstance();
    MonopolyEngine() = default; 
    ~MonopolyEngine() = default;

    MonopolyEngine(const MonopolyEngine&) = delete;             
    MonopolyEngine& operator=(const MonopolyEngine&) = delete;
    MonopolyEngine(MonopolyEngine&&) = delete;                   
    MonopolyEngine& operator=(MonopolyEngine&&) = delete;
public:
    static MonopolyEngine& getInstance();
    void run();
};