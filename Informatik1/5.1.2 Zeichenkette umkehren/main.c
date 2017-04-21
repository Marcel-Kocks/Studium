#include <stdio.h>
#include <stdlib.h>

void StrBackward(char* pfront) {
	char* pback = pfront;
	for (; *pback != 0; pback++)
		;
	pback--;
	for (; pfront < pback; pfront++, pback--) {
		char c = *pback;
		*pback = *pfront;
		*pfront = c;
	}
}

void main() {
	char input[100];

	printf("Zeichenkette zum umkehen eingeben: ");
	scanf_s("%s", input,100);

	StrBackward(input);

	printf("\nAusgabe: %s\n", input);
}