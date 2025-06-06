#pragma once

class MonopolyEngine
{
private:
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