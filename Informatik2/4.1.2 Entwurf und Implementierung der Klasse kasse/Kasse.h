#pragma once
#include "geldmenge.h"

class Kasse
{
protected:
	geldmenge eigeneKasse;
public:
	geldmenge kundeZahlt(int zuBezahlen, geldmenge abgegeben); //retrun null = zu wenig geld;
};
