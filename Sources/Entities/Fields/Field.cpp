#include "../../../Headers/Entities/Fields/Field.h"

Field::Field(int index, const MyString& descr, int color)
{
	indexOnBoard = index;
	description = descr;
	this->color = color;
}

int Field::getFieldIndex() const
{
	return indexOnBoard;
}

int Field::getColor() const
{
	return color;
}

	//namespace
	//{
	//	const int FG_BLACK_BG_GREY = 0 + 16 * 8;
	//	const int FG_WHITE_BG_BLUE = 15 + 16 * 1;
	//	const int FG_WHITE_BG_GREEN = 15 + 16 * 2;
	//	const int FG_BLACK_BG_AQUA = 0 + 16 * 3;
	//	const int FG_WHITE_BG_RED = 15 + 16 * 4;
	//	const int FG_WHITE_BG_PURPLE = 15 + 16 * 5;
	//	const int FG_BLACK_BG_YELLOW = 0 + 16 * 6;
	//	const int FG_BLACK_BG_LIGHTRED = 0 + 16 * 12;
	//	const int FG_WHITE_BG_BLACK = 15 + 16 * 0;
	//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//	SetConsoleTextAttribute(hConsole, FG_WHITE_BG_BLACK);
	//
	//}