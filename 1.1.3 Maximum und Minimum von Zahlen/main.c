# include <stdio.h>
# include <stdlib.h>

void main() {
	int max = 0, min = 0, anzahl, eingabe;

	printf("Anzahl:");
	scanf_s("%d", &anzahl);
	printf("\n");

	for (int i = 1; i <= anzahl; i++)
	{
		printf("%d. Zahl: ",i);
		scanf_s("%d", &eingabe);

		if (eingabe > max) {
			max = eingabe;
		}
		else {
			if (eingabe < min) {
				min = eingabe;
			}
		}
	}

	printf("\nGroesste Zahl: %d\n", max);
	printf("Kleinste Zahl: %d\n", min);
}