// 1.1.3 ggT (iterativ und rekursiv).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int ggT_rek(int a, int b) {
	if (a == b)
		return a;
	if (a > b)
		a = a - b;
	else
		b = b - a;
	return ggT_rek(a, b);
}

int ggT_iter(int a, int b) {
	for (; a != b;) {
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}

int main()
{
	printf("GGT von %d und %d ist: %d\n", 60, 36, ggT_rek(60, 36));
	printf("GGT von %d und %d ist: %d\n", 60, 36, ggT_iter(60, 36));
    return 0;
}

