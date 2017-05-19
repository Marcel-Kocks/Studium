#include "player.h"
#include <iostream>


using namespace std;
player::player()
{
	name = "";
}

void player::init(const std::string & playname, const set & playercard)
{
	name = playname;
	card = playercard;
	cout << "Spieler: " << name << " Karte: " << playercard;
}

void player::streiche(unsigned short number)
{
	card -= number;
}

bool player::hasBingo()
{
	return !card;
}


const std::string & player::getName()
{
	return name;
}

std::ostream & operator<<(std::ostream & os, const player & p)
{
	os << "Player: " << p.name << " Karte: " << p.card;
	return os;
}
