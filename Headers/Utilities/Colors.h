#pragma once

class Colors
{
public:
	static const int DEFAULT_COLOR = 0 + 16 * 0;
	static const int FG_BLACK_BG_GREY = 0 + 16 * 8;
	static const int FG_WHITE_BG_BLUE = 15 + 16 * 1;
	static const int FG_WHITE_BG_GREEN = 15 + 16 * 2;
	static const int FG_BLACK_BG_AQUA = 0 + 16 * 3;
	static const int FG_WHITE_BG_RED = 15 + 16 * 4;
	static const int FG_WHITE_BG_PURPLE = 15 + 16 * 5;
	static const int FG_BLACK_BG_YELLOW = 0 + 16 * 6;
	static const int FG_BLACK_BG_LIGHTRED = 0 + 16 * 12;
	static const int FG_WHITE_BG_BLACK = 15 + 16 * 0;
};
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hConsole, DEFAULT_COLOR);