#include <stdio.h>
#include <stdlib.h>

int pow(int x, int y) {
	int erg = x;
	for (; y > 1; y--) {
		erg *= x;
	}
	return erg;
}


void main() {
	int x = 2;
	int y = 5;

	printf("Erg: %d\n", pow(x, y));
}