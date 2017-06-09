#include "Kasse.h"

geldmenge Kasse::kundeZahlt(int zuBezahlen, geldmenge abgegeben)
{
	int insum = abgegeben.getSumme();
	if (zuBezahlen > insum) {
		throw "Not enougth money paid!";
	}

	eigeneKasse += abgegeben;

	if (zuBezahlen == insum) {
		return geldmenge();
	}

	int change = insum - zuBezahlen;

	geldmenge wechsel;
	

	throw "No possible change configuration!";
}
