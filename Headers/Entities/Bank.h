#pragma once
#include "../Entities/Trade.h"

class Bank
{
private:
    MyVector<Trade> trades;
    Bank();
    ~Bank() = default;

    Bank(const Bank&) = delete;
    Bank& operator=(const Bank&) = delete;
    Bank(Bank&&) = delete;
    Bank& operator=(Bank&&) = delete;
public:
    static Bank& getInstance();

};