#include "../../Headers/Entities/Board.h"

Board& Board::getInstance() 
{
	static Board instance;
	return instance;
}

void Board::generate()
{
	StartField start(0, "This is the starting field. Pass by and get 100$!");
	fields.pushBack(start);
	for (size_t i = 1; i < 4; i++)
	{
		// here prices are modified to be going up, like in the real game, with a small difference in price
		Property prop(i, "Cheap buildings, but many people get here.", Colors::FG_BLACK_BG_YELLOW, 50 + i, 250 + i, 125 + i, 175 + i);
		fields.pushBack(prop);
	}

	CarPark park1(4, "Chill in the park, you deserve it.");
	fields.pushBack(park1);
	for (size_t i = 5; i < 8; i++)
	{
		Property prop(i, "The downtown buildings, prices get steeper.", Colors::FG_BLACK_BG_AQUA, 50 + i, 250 + i, 125 + i, 175 + i);
		fields.pushBack(prop);
	}

	JailField jail(8, "Skip at least 1 move. Roll the dice or pay 200$ to bail out.", 200);
	fields.pushBack(jail);
	for (size_t i = 9; i < 12; i++)
	{
		Property prop(i, "Mid buildings, not too much traffic.", Colors::FG_BLACK_BG_LIGHTRED, 50 + i, 250 + i, 125 + i, 175 + i);
		fields.pushBack(prop);
	}

	CarPark park2(12, "Chill in the park, you deserve it.");
	fields.pushBack(park2);
	for (size_t i = 13; i < 16; i++)
	{
		Property prop(i, "Affordable buildings, with mild popularity.", Colors::FG_WHITE_BG_GREEN, 50 + i, 250 + i, 125 + i, 175 + i);
		fields.pushBack(prop);
	}

	CardField cardF1(16, "Draw a card. It might be good, or not...");
	fields.pushBack(cardF1);
	for (size_t i = 17; i < 20; i++)
	{
		Property prop(i, "The city center, but not the most expensive.", Colors::FG_WHITE_BG_RED, 50 + i, 250 + i, 125 + i, 175 + i);
		fields.pushBack(prop);
	}

	GoToJailField goToJail(20, "Sent to jail!", 8);
	fields.pushBack(goToJail);
	for (size_t i = 21; i < 24; i++)
	{
		Property prop(i, "The luxorious fields of town.", Colors::FG_WHITE_BG_BLUE, 50 + i, 250 + i, 125 + i, 175 + i);
		fields.pushBack(prop);
	}

	CardField cardF2(24, "Draw a card. It might be good, or not...");
	fields.pushBack(cardF2);
	for (size_t i = 25; i < 28; i++)
	{
		Property prop(i, "Office buildings, really expensive.", Colors::FG_BLACK_BG_GREY, 50 + i, 250 + i, 125 + i, 175 + i);
		fields.pushBack(prop);
	}

	CarPark park3(28, "Chill in the park, you deserve it.");
	fields.pushBack(park3);
	for (size_t i = 29; i < 31; i++)
	{
		Property prop(i, "The best buildings, get them while you can.", Colors::FG_WHITE_BG_PURPLE, 50 + i, 250 + i, 125 + i, 175 + i);
		fields.pushBack(prop);
	}
}

int Board::getBoardSize() const
{
	return fields.getSize();
}

int Board::getJailTax() const
{
	return dynamic_cast<const JailField*>(fields[getJailIndex()])->getFeeForEscape();
}

Field* Board::getField(int index)
{
	return fields[index];
}

const Field* Board::getField(int index) const
{
	return fields[index];
}

int Board::getJailIndex() const
{
	for (size_t i = 0; i < getBoardSize(); i++)
	{
		if (dynamic_cast<const JailField*>(fields[i]))
		{
			return i;
		}
	}

	throw std::logic_error("Could not find jail index.");
}

void Board::printPropertiesFor(Player& player)
{
	// todo
	for (size_t i = 0; i < getBoardSize(); i++)
	{
		Property* prop = dynamic_cast<Property*>(fields[i]);

		if (prop == nullptr)
		{
			continue;
		}

		if (prop->isOwner(player))
		{
			std::cout << prop->getFieldIndex() << std::endl;
			std::cout << prop->getDescription() << std::endl;
			// std::cout << prop->getColor() << std::endl;
		}
	}
}

void Board::printBoard() const
{
	// todo
}