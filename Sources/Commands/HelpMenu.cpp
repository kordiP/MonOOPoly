#include "../../Headers/Commands/HelpMenu.h"

void HelpMenu::execute() const
{
	std::cout << "Welcome to MonOOPoly! Here is a list of all commands: " << std::endl;

	std::cout << "NewGame: start a new game." << std::endl;
	std::cout << "ContinueGame <not yet implemented>. " << std::endl;
	std::cout << "HelpMenu: this is it! " << std::endl;
	std::cout << "ProposeTrade: make a trade to another player for one of their buildings. " << std::endl;
	std::cout << "Resign: resign from the game. " << std::endl;
	std::cout << "RollDice: the most basic function, make turns with it. " << std::endl;
	std::cout << "SellProperty: sell any of your properties to the bank. " << std::endl;
	std::cout << "SetMortgage: buy mortgage for a building in a neighbourhood that is fully yours. " << std::endl;
	std::cout << "ViewTrades: look at all trades for you from the other players. " << std::endl;
	std::cout << "AcceptTrade: accept given ongoing trade. " << std::endl;
}
