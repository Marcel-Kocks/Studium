#pragma once

#include <map>


class geldmenge
{

	friend std::ostream & operator<<(std::ostream &o, const geldmenge &g);
protected:
	std::map<int, int> m;

public:
	int getSumme();

	geldmenge operator+=(geldmenge& rhs);
	geldmenge operator-=(int Betrag);

	void set(int key, int value);

	int get(int key);

	void add(int key, int value);


	
	geldmenge();
};

