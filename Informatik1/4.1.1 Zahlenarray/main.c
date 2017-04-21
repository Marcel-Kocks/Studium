# include <stdio.h>
# include <stdlib.h>

void main() {
#define ZahlLengh 10
	int Zahl[ZahlLengh];

	for (int i = 0; i < ZahlLengh; i++) {
		printf("Gebe die %2d. Zahl ein: ", i + 1);
		scanf_s("%d", &Zahl[i]);
	}

	while (1) {
		int input;
		printf("\n\n\nWelche Zahl soll ausgegeben werden? (1-%d)",ZahlLengh);
		scanf_s("%d", &input);
		printf("Die %d. Zahl ist: %d", input, Zahl[input - 1]);
	}
}