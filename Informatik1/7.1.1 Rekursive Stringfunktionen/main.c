#include <stdlib.h>
#include <stdio.h>

int strlen(char* string) {
	if (*string == 0) {
		return 0;
	}
	else {
		return 1 + strlen(++string);
	}
}

int strcmp(char* str1, char* str2) {
	if (*str1 != 0 && *str2 == *str1) {
		return strcmp(++str1, ++str2);
	}
	return *str1 - *str2;
}

void main() {
	char* in1 = "hallo";
	char* in2 = "hallp";
	printf("%s ist %d-Zeichen lang.\n", in1, strlen(in1));
	printf("Vergleich: %d\n", strcmp(in1, in2));
}