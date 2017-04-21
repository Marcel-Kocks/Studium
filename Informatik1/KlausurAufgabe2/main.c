#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>

unsigned int fkt(unsigned int in) {
	char muster = 0;
	muster = ~muster;
	unsigned int erg = 0;
	for (int i = 0; i < sizeof(unsigned int); i++) {
		in = in >> 8;
		erg = erg | (in & muster);
		erg = erg << 8;
	}
	return erg;
}


void main() {
	unsigned int in;
	printf("Hex-Zahl eingeben: ");
	scanf("%x", &in);
	char test = in;
	printf("In: %x\n", in);
	unsigned int out = fkt(in);
	printf("Out: %x\n", out);
}