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

const MyString& Field::getDescription() const
{
	return description;
}