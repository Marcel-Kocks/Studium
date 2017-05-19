#include "gamemaster.h"
#include <iostream>
#include <Windows.h>



gamemaster::gamemaster(unsigned short raffledrumsize, unsigned short playcardsize):drum(raffledrumsize)
{
	(*this).raffledrumsize = raffledrumsize;
	(*this).playcardsize = playcardsize;
}

void gamemaster::play()
{
	bool winner = false;

	while (!winner) {
		Sleep(250);
		unsigned short got = drum.raffle();
		std::cout << "Zahl gezogen: " << got << std::endl;
		
		for (player & s : players) {
			s.streiche(got);
			std::cout << s;
			if (s.hasBingo()) {
				printf("BINGO!\n");
				winner = true;
			}
		}
	}
}


void gamemaster::createPlayer(std::string playername)
{
	player newplayer;
	set playercard;

	raffledrum tmp(raffledrumsize);
	for (short i = 0; i < 10; i++) {
		playercard += tmp.raffle();
	}

	newplayer.init(playername, playercard);

	players.push_back(newplayer);
}

