// 1.1.4 Die meisten geraden Zahlen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "1.1.4 Die meisten geraden Zahlen.h"

int zahlen[200][300];

int anzahlgerade(int i) {
	int count = 0;
	for (int a = 0; a < 300; a++) {
		count += zahlen[i][a] % 2 == 0;
	}
	return count;
}

void fillwithrandom() {
	for (int a = 0; a < 200; a++) {
		for (int b = 0; b < 300; b++)
		{
			zahlen[a][b] = rand();
		}
	}
}

int main()
{
	fillwithrandom();

	int topIndex = -1;
	int topIndexCount = -1;

	for (int i = 0; i < 200; i++) {
		int c = anzahlgerade(i);
		if (c > topIndexCount) {
			topIndex = i;
			topIndexCount = c;
		}
	}

	printf("TopIndex %d mit %d geraden Zahlen\n", topIndex, topIndexCount);
	system("PAUSE");
    return 0;
}

