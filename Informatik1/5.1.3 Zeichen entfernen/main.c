#include <stdio.h>
#include <stdlib.h>

void StrRemoveChar(char* str, char c) {
	char* org = str;
	for (; *str != 0; str++) {
		if (*str != c) {
			*org = *str;
			org++;
		}
	}
	*org = 0;
}

void main() {
	char input[100];
	char c;

	printf("Zeichenkette eingeben: ");
	scanf_s("%s", input, 100);

	printf("Zu entfernendes Zeichen eingeben: ");
	scanf_s("\n%c", &c,1);

	StrRemoveChar(input, c);

	printf("\nAusgabe: %s\n", input);

}