#include "raffledrum.h"


raffledrum::raffledrum(unsigned short count)
{
	countstart = count;
	countremain = count;
	for (unsigned short inc = 0; inc < count; inc++)
		drum += inc;
}

unsigned short raffledrum::raffle()
{
	if (countremain <= 0)
		return -1;
	unsigned short ran = rand() % countremain;
	
	//ran 'te noch vorhandene Kugel ziehen
	unsigned short a, erg;
	for (a = 0, erg = 0; a <= ran; erg++) {
		if (erg < drum)
			a++;
	}
	erg--;

	drum -= erg;
	countremain--;

	return erg;
}

