/*
	Atanas Kordov, 5MI0600508
*/
#include "../Headers/MonopolyEngine.h"
#include "../Headers/Utilities/MyString.h"
#include "../Headers/Utilities/HeterogenousContainer.hpp"
#include "../Headers/Utilities/MyVector.hpp"
#include "../Headers/Utilities/Stack.hpp"

#include <cstdlib>
#include <crtdbg.h>

int main() 
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	MonopolyEngine& engine = MonopolyEngine::getInstance();
	engine.run();
}