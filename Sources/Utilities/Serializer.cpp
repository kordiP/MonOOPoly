#include "../../Headers/Utilities/Serializer.h"



Serializer& Serializer::getInstance()
{
	static Serializer instance;
	return instance;
}

void Serializer::readBoard()
{

}

void Serializer::readPlayers()
{

}

void Serializer::createGameSave()
{
    {
        std::ofstream ofs(BOARD_LOCATION.c_str(), std::ios::binary);
        if (!ofs)
        {
            std::cerr << "Failed to open " << BOARD_LOCATION << " for writing.\n";
            return;
        }

        int fieldCount = data.getBoardSize();
        ofs.write(reinterpret_cast<const char*>(&fieldCount), sizeof(fieldCount));

        for (int i = 0; i < fieldCount; i++)
        {
            Field* field = data.getFieldAt(i);
            field->saveToFile(ofs);
        }
    }

    {
        std::ofstream ofs(PLAYERS_LOCATION.c_str(), std::ios::binary);
        if (!ofs)
        {
            std::cerr << "Failed to open " << PLAYERS_LOCATION << " for writing.\n";
            return;
        }

        int playerCount = data.getPlayersCount();
        ofs.write(reinterpret_cast<const char*>(&playerCount), sizeof(playerCount));

        for (int i = 0; i < playerCount; i++)
        {
            Player& player = data.getPlayerAt(i);
            player.saveToFile(ofs);
        }
    }
}


void Serializer::readGameSave()
{

}
