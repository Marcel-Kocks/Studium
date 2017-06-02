#pragma once

#include <map>


class geldmenge
{
protected:
	std::map<int, int> m;

public:
	int getSumme();

	geldmenge operator+=(geldmenge& rhs);

	geldmenge();
};

