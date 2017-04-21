#include <stdio.h>
#include <stdlib.h>

void main() {
	int n;
	int direktor = 40, ober = 160, normal = 1000;

	printf("Durchläuft: ");
	scanf_s("%d", &n);

	for (int i = 1; i <= n; i++) {
		int wechsel;
		direktor = (float)direktor * 0.8;
		ober = (float)ober * 0.8;
		normal = (float)normal * 0.8;

		wechsel = (float)ober * 0.1;
		ober -= wechsel;
		direktor += wechsel;

		wechsel = (float)normal * 0.2;
		normal -= wechsel;
		ober += wechsel;

		normal = 1200 - direktor - ober;

		printf("%3d %4d %4d %4d\n", i, direktor, ober, normal);
	}

}