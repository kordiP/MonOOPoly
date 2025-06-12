#pragma once
#include "Command.h"
#include "AcceptTrade.h"
#include "BuyProperty.h"
#include "ContinueGame.h"
#include "HelpMenu.h"
#include "ProposeTrade.h"
#include "Resign.h"
#include "RollDice.h"
#include "SellProperty.h"
#include "SetMortgage.h"
#include "StartNewGame.h"
#include "WelcomeScreen.h"
#include "../Utilities/MyString.h"

class CommandInterpretor
{
private:
    CommandInterpretor();
    ~CommandInterpretor() = default;

    CommandInterpretor(const CommandInterpretor&) = delete;
    CommandInterpretor& operator=(const CommandInterpretor&) = delete;
    CommandInterpretor(CommandInterpretor&&) = delete;
    CommandInterpretor& operator=(CommandInterpretor&&) = delete;

public:
    static CommandInterpretor& getInstance();
    void executeCommand(const MyString&);
};