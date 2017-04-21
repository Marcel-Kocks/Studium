#include <stdlib.h>
#include <stdio.h>

void bubble(int* data, int lengh) {
	for (int i = 0; i < lengh - 1; i++) {
		if (data[i] > data[i + 1]) {
			int c = data[i];
			data[i] = data[i + 1];
			data[i + 1] = c;
		}
	}
	if (lengh > 1)
		bubble(data, lengh - 1);
}

void main() {
	int in[] = {15,1,13,15,12,5,8,7};

	for (int i = 0; i < 8; i++) {
		printf("%4d", in[i]);
	}

	printf("\n");
	bubble(in,8);

	for (int i = 0; i < 8; i++) {
		printf("%4d", in[i]);
	}

	printf("\n");
}