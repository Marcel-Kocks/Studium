#include "stdafx.h"
#include "Date.h"

using namespace std;

Date::Date()
{
	Date(01, 01, 1900);
}

Date::Date(int Tag, int Monat, int Jahr)
{
	setDatum(Tag, Monat, Jahr);
}

void Date::setDatum(int Tag, int Monat, int Jahr)
{
	day = Tag;
	month = Monat;
	year = Jahr;
}

void Date::setDatum(struct Date::sDatum in)
{

}

Date::sDatum Date::getDatum()
{
	return Date::sDatum();
}


void Date::setTag(int Tag)
{
	Date::sDatum o = Date::getDatum();
	o.day = Tag;
	setDatum(o);
}

void Date::setMonat(int Monat)
{
	Date::sDatum o = Date::getDatum();
	o.month = Monat;
	setDatum(o);
}

void Date::setJahr(int Jahr)
{
	Date::sDatum o = Date::getDatum();
	o.year = Jahr;
	setDatum(o);
}


Date::Wochentag Date::getWochentag() {
	days = 15;
	return Date::Wochentag(days%7);
}

Date::~Date()
{
}

char * Date::toString()
{
	char * out = (char*)malloc(sizeof(char)*11);
	snprintf(out, 11, "%02d.%02d.%04d", day, month, year);
	return out;
}

