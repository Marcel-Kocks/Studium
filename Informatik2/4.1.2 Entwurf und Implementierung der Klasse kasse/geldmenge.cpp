#include "geldmenge.h"



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

geldmenge::geldmenge()
{
	m[1] = 0;
	m[2] = 0;
	m[5] = 0;
	m[10] = 0;
	m[20] = 0;
	m[50] = 0;
	m[100] = 0;
	m[200] = 0;
	m[500] = 0;
	m[1000] = 0;
	m[2000] = 0;
	m[5000] = 0;
	m[10000] = 0;
	m[20000] = 0;
	m[50000] = 0;
}
