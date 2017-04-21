#include <stdio.h>
#include <stdlib.h>

void cleanStr(char* input, char* output) {
	int i = 1;
	output[0] = input[0];
	for (; *input != 0; input++) {
		if (output[i - 1] == *input) {
			continue;
		}
		output[i] = *input;
		i++;
	}
	output[i] = 0;
}

void main() {
	char input[100];
	printf("Zeichenkette eingeben: ");
	scanf_s("%s", input, 100);
	char output[100] ;
	cleanStr(input, output);
	printf("Ausgabe: %s\n", output);
}