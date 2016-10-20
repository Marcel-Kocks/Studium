# include <stdio.h>
# include <stdlib.h>

void main() {
	signed int min = ~0u >> 1, max = min + 1,  anzahl, eingabe;

	printf("Anzahl:");
	scanf_s("%d", &anzahl);
	printf("\n");

	for (int i = 1; i <= anzahl; i++)
	{
		printf("%d. Zahl: ", i);
		scanf_s("%d", &eingabe);

		if (eingabe > max) {
			max = eingabe;
		}

		if (eingabe < min) {
			min = eingabe;
		}

	}

	printf("\nGroesste Zahl: %d\n", max);
	printf("Kleinste Zahl: %d\n", min);
}