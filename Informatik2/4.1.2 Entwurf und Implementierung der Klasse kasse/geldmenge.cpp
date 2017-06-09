#include "geldmenge.h"
#include <iostream>
#include <iomanip>


int geldmenge::getSumme()
{
	int summe = 0;
	for (auto t : m) {
		summe += t.first*t.second;
	}
	return summe;
}

geldmenge geldmenge::operator+=(geldmenge & rhs)
{
	for (auto x : rhs.m) {
		m[x.first] += x.second;
	}
	return *this;
}

geldmenge geldmenge::operator-=(int Betrag)
{
	return geldmenge();
}

void geldmenge::set(int key, int value)
{
	for (auto x : m) {
		if (x.first == key)
			x.second = value;
	}
}

int geldmenge::get(int key)
{
	for (auto x : m) {
		if (x.first == key)
			return x.second;
	}
	throw "Key not found!";
}

void geldmenge::add(int key, int value)
{
	set(key, get(key) + value);
}

geldmenge::geldmenge()
{
	m[50000] = 0;
	m[20000] = 0;
	m[10000] = 0;
	m[5000] = 0;
	m[2000] = 0;
	m[1000] = 0;
	m[500] = 0;
	m[200] = 0;
	m[100] = 0;
	m[50] = 0;
	m[20] = 0;
	m[10] = 0;
	m[5] = 0;
	m[2] = 0;
	m[1] = 0;
}

std::ostream & operator<<(std::ostream & o, const geldmenge & g)
{
	o << std::endl;
	for (auto x : g.m) {
		o << std::setw(6) << x.first;
	}
	o << std::endl;
	for (auto x : g.m) {
		o << std::setw(6) << x.second;
	}
	o << std::endl;

	return o;
}
