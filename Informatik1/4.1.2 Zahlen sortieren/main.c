# include <stdio.h>
# include <stdlib.h>

void main() {
#define ZahlLengh 10
	int Zahl[ZahlLengh];

	for (int i = 0; i < ZahlLengh; i++) {
		printf("Gebe die %2d. Zahl ein: ", i + 1);
		scanf_s("%d", &Zahl[i]);
	}

	for (int i = 0; i < ZahlLengh; i++)
		for (int a = 0; a < ZahlLengh - 1; a++) {
			if (Zahl[a] > Zahl[a + 1]) {
				//tauschen
				int c = Zahl[a];
				Zahl[a] = Zahl[a + 1];
				Zahl[a + 1] = c;
			}
		}

	for (int i = 0; i < ZahlLengh; i++) {
		printf("%d ", Zahl[i]);
	}

}