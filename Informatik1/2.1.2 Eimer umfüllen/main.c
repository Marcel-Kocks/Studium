#include <stdio.h>
#include <stdlib.h>

void main() {
	float x, y, a, b;
	int n;

	printf("F�llung Eimer x: ");
	scanf_s("%f", &x);
	printf("F�llung Eimer y: ");
	scanf_s("%f", &y);

	printf("Umf�llen aus x nach y in Prozent: ");
	scanf_s("%f", &a);
	printf("Umf�llen aus y nach x in Prozent: ");
	scanf_s("%f", &b);

	printf("Wie oft?:");
	scanf_s("%d",&n);

	printf("\n\nn    x      y     \n");

	for (int i = 1; i <= n; i++) {
		float abzug;
		abzug = x*a / 100;
		y = y + abzug;
		x -= abzug;

		abzug= y*b / 100;
		x = x + abzug;
		y -= abzug;

		printf("%4d %6.2f %6.2f\n",i,x,y);
	}
}