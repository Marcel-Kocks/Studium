#include <stdio.h>
#include <stdlib.h>

int StrCompare(char* str1, char* str2) {

	for (; (*str1 == *str2) && (*str1 != 0); str1++, str2++)
		;
	if (*str1 == *str2) {
		return 0;
	}
	if (*str1 > *str2) {
		return 1;
	}
	if (*str1 < *str2) {
		return -1;
	}
}

void main() {
	char in1[100];
	char in2[100];

	printf("1. Zeichenkette eingeben: ");
	scanf_s("%s", in1,100);

	printf("2. Zeichenkette eingeben: ");
	scanf_s("%s", in2,100);

	printf("\nVergleich ergibt: %d\n\n", StrCompare(in1, in2));
}