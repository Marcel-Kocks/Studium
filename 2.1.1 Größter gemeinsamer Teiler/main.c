#include <stdio.h>
#include <stdlib.h>

void main() {
	int zahl1, zahl2, c;

	printf("Zahl 1:");
	scanf_s("%d", &zahl1);
	printf("Zahl 2:");
	scanf_s("%d", &zahl2);

	while (zahl1 != zahl2) {
		if (zahl1 < zahl2) {
			c = zahl1;
			zahl1 = zahl2;
			zahl2 = c;
		}
		int erg = zahl1 - zahl2;
		printf("%d - %d = %d \n", zahl1, zahl2, erg);
		zahl1 = erg;
	}
	printf("ggT: %d \n", zahl1);
}