#include<stdlib.h>
#include<stdio.h>

short HigherMoreBitsThanLower(unsigned short in) {
	short low = 0, high = 0;

	for (int i = 0; i<8; i++) {
		low += in & 1;
		in = in >> 1;
	}
	for (int i = 0; i<8; i++) {
		high += in & 1;
		in = in >> 1;
	}
	if (high>low)
		return 1;
	return 0;
}

void main() {
	printf("In: %4d Out: %4d\n", 0x2A0F, HigherMoreBitsThanLower(0x2A0F));
	printf("In: %4d Out: %4d\n", 0xF1E2, HigherMoreBitsThanLower(0xF1E2));
	system("pause");
}
