#include<stdio.h>

void varmax(int* dataStart, int* dataEnd, int* max1, int* max2) {
	*max1 = *dataStart;
	*max2 = *max1;
	for (; dataStart <= dataEnd; dataStart++) {
		if (*dataStart > *max1) {
			*max2 = *max1;
			*max1 = *dataStart;
		}
		else {
			if (*dataStart > *max2) {
				*max2 = *dataStart;
			}
		}
	}
}

void main() {
	int zahlen[20] = { 1,2,3,4,5,6,7,8,9,10,22,12,13,14,15,16,17,18,19,20 };
	int eins, zwei;

	varmax(zahlen, zahlen + 19, &eins, &zwei);

	printf("Groesste: %d\n", eins);
	printf("Zweitgroesste: %d\n", zwei);
}