#pragma once

class Bank
{
private:
    Bank();
    ~Bank() = default;

    Bank(const Bank&) = delete;
    Bank& operator=(const Bank&) = delete;
    Bank(Bank&&) = delete;
    Bank& operator=(Bank&&) = delete;
public:
    static Bank& getInstance();
};