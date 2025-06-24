/*
	Atanas Kordov, 5MI0600508
*/
#include "../Headers/MonopolyEngine.h"
#include "../Headers/Utilities/MyString.h"
#include "../Headers/Utilities/HeterogenousContainer.hpp"
#include "../Headers/Utilities/MyVector.hpp"
#include "../Headers/Utilities/Stack.hpp"
int main() 
{
	MonopolyEngine& engine = MonopolyEngine::getInstance();
	engine.run();
}