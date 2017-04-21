#include<stdlib.h>
#include<stdio.h>

unsigned int swap(unsigned int in) {
	unsigned int out = 0;
	unsigned short pattern = 0xFF;

	for (int i=0; i < sizeof(unsigned int) ;i ++, in = in >> 8) {
		out = out << 8;
		out = out | in & pattern;
	}

	return out;
}

void main() {
	int num[] = { 1,257,111,4711, 0x0F0F0F0F };
	for (int i = 0; i < 5; i++) {
		printf("In: %4d Out: %4d\n", num[i], swap(num[i]));
	}
	system("pause");
}