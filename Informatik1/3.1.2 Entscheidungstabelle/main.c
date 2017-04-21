# include <stdio.h>
# include <stdlib.h>

void main() {
	int input;
	int inputresult = 0;

	printf("Lieferfähig? (1/0): ");
	scanf_s("%d", &input);
	inputresult = inputresult | input << 2;

	printf("Angaben vollständig? (1/0): ");
	scanf_s("%d", &input);
	inputresult = inputresult | input << 1;

	printf("Bonität in Ordnung? (1/0): ");
	scanf_s("%d", &input);
	inputresult = inputresult | input << 0;

	printf("\n\n");

	int output[8];
	output[7] = 0 | 1 << 0 | 0 << 1 | 0 << 2 | 0 << 3;
	output[6] = 0 | 0 << 0 | 1 << 1 | 0 << 2 | 0 << 3;
	output[5] = 0 | 1 << 0 | 0 << 1 | 1 << 2 | 0 << 3;
	output[4] = 0 | 0 << 0 | 1 << 1 | 1 << 2 | 0 << 3;
	output[3] = 0 | 0 << 0 | 0 << 1 | 0 << 2 | 1 << 3;
	output[2] = 0 | 0 << 0 | 0 << 1 | 0 << 2 | 1 << 3;
	output[1] = 0 | 0 << 0 | 0 << 1 | 0 << 2 | 1 << 3;
	output[0] = 0 | 0 << 0 | 0 << 1 | 0 << 2 | 1 << 3;


	if (output[inputresult] & (1 << 0)) {
		printf("Lieferung mit Rechnung\n");
	}

	if (output[inputresult] & (1 << 1)) {
		printf("Lieferung als Nachnahme\n");
	}

	if (output[inputresult] & (1 << 2)) {
		printf("Angaben vervollständigen\n");
	}

	if (output[inputresult] & (1 << 3)) {
		printf("Mitteilen: nicht lieferbar\n");
	}
}