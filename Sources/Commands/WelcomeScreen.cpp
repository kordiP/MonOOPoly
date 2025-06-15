#include "../../Headers/Commands/WelcomeScreen.h"

void WelcomeScreen::execute() const
{
	std::cout << "Welcome to MonOOPoly!" << std::endl;
	std::cout << "1. Start New Game by typing \"NewGame\"" << std::endl;
	std::cout << "2. Continue Last Game by typing \"ContinueGame\"" << std::endl;
	std::cout << "3. See All Commands / Help Menu by typing \"HelpMenu\"" << std::endl;
	std::cout << "4. Exit by typing \"EndGame\"" << std::endl;
}
