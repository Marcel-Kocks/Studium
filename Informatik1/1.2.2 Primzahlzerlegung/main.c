#include <stdio.h>
#include <stdlib.h>

void main() {
	int zahl;

	printf("Zahl: ");
	scanf_s("%d", &zahl);

	printf("%d = ", zahl);

	for (int i = 2; i <= zahl ; i++)
	{
		if (zahl % i == 0) {
			printf("%d", i);
			zahl = zahl / i;
			if (zahl > 1) {
				printf("*");
			}
			i = 1;
		}
	}
	printf("\n");
}