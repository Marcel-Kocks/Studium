#pragma once
#include "set.h"
#include <string>
class player
{
	friend std::ostream& operator<< (std::ostream& os, const player& p);

public:
	player();
	void init(const std::string& playername, const set & playercard);
	void streiche(unsigned short number);
	bool hasBingo();
	const std::string & getName();
private:
	std::string name;
	set card;
};

