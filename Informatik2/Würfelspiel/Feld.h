#pragma once
#include "Figur.h"
class Feld
{
protected:
	Figur *figures[4];

public:
	virtual void figurSetzen();
	virtual bool blockiert() { return false; };
	virtual void step();
	Feld();
	~Feld();
};

