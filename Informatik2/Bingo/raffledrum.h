#pragma once
#include "set.h"
class raffledrum
{
public:
	raffledrum(unsigned short count=50);
	unsigned short raffle();

private:
	unsigned short countstart,countremain;
	set drum;
};

