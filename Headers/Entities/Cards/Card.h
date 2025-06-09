#pragma once

class Card
{
public:
	virtual Card* clone() const = 0;
};