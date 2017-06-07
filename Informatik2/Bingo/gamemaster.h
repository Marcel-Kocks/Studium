#pragma once
#include <string>
#include <vector>
#include "raffledrum.h"
#include "player.h"

class gamemaster
{
public:
	gamemaster::gamemaster(unsigned short raffledrumsize=50, unsigned short playcardsize=10);
	void play();
	void createPlayer(std::string playername);
private:
	raffledrum drum;
	std::vector<player> players;
	unsigned short raffledrumsize;
	unsigned short playcardsize;
};

