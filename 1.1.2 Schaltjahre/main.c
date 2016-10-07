# include <stdio.h>
# include <stdlib.h>

void main() {
	int eingabe;

	printf("Bitte Jahreszahl zum Testen eingeben:");
	scanf_s("%d", &eingabe);

	if (eingabe % 4 == 0) {
		if (eingabe % 100 == 0) {
			if (eingabe % 400 != 0) {
				printf("%d ist kein Schaltjahr.\n", eingabe);
				return;
			}
		}
		printf("%d ist ein Schaltjahr.\n", eingabe);
	}
	else {
		printf("%d ist kein Schaltjahr.\n", eingabe);
	}
}