#include <stdio.h>
#include <stdlib.h>
int StrToInt(char* str) {
	int res = 0;
	for (; *str != 0; str++) {
		res = res * 10 + (*str - '0');
	}
	return res;
}

void main() {
	char input[100];

	printf("Zahl eingeben: ");
	scanf_s("%s", input, 100);

	printf("Eingabe: %d\n", StrToInt(input));
}