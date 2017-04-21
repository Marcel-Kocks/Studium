// 1.1.2 Dualdarstellung.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

short count(int a) {
	short count = 0;
	for (; a; a = a >> 1) {
		count += a & 1;
	}
	return count;
}

int main()
{
	for (short i = 0; i <= 4711; i++) {
		if (count(i) == 3) {
			printf("%d\n", i);
		}
	}
    return 0;
}



