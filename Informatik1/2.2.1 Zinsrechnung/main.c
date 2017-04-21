#include <stdio.h>
#include <stdlib.h>

void main() {
	float Kapital, Grenze, Zinssatz;

	printf("Startkapital: ");
	scanf_s("%f", &Kapital);
	printf("Zielkapital: ");
	scanf_s("%f", &Grenze);
	printf("Zinssatzt in Prozent: ");
	scanf_s("%f", &Zinssatz);

	for (int i = 1; Kapital < Grenze; i++) {
		Kapital += Kapital*Zinssatz / 100;
		printf("%3d. %10f\n",i,Kapital);
	}
}