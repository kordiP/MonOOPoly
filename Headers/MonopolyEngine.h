#pragma once
#include <iostream>
#include "../Headers/Utilities/MyString.h"
#include "../Headers/Utilities/MyVector.hpp"
#include "../Headers/Entities/Board.h"
#include "../Headers/Entities/Player.h"
#include "../Headers/Entities/Bank.h"
#include "../Headers/Entities/Cards/CardDeck.h"
#include "../Headers/Commands/CommandInterpretor.h"

class MonopolyEngine
{
private:
    MonopolyEngine(); 
    ~MonopolyEngine() = default;

    MonopolyEngine(const MonopolyEngine&) = delete;             
    MonopolyEngine& operator=(const MonopolyEngine&) = delete;
    MonopolyEngine(MonopolyEngine&&) = delete;                   
    MonopolyEngine& operator=(MonopolyEngine&&) = delete;
public:
    static MonopolyEngine& getInstance();
    void run();
};