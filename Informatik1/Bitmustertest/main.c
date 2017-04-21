#include<stdlib.h>
#include<stdio.h>

int funktion(unsigned int u, unsigned int pattern, int plen) {
	unsigned int cpPattern = 0;
	for (int i = 0; i<plen; i++) {
		cpPattern = cpPattern << 1 | 1;
	}
	for (; u; u = u >> 1) {
		if ((u&cpPattern) == pattern)
			return 1;
	}
	return 0;
}

void main() {
	printf("In: %8d Out: %2d\n", 14044, funktion(14044, 7, 3));
	printf("In: %8d Out: %2d\n", 14040, funktion(14040, 7, 3));
}