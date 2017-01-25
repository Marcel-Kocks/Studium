#include<stdlib.h>
#include<stdio.h>

unsigned short swap(unsigned short in) {
	return (in& 0x00FF) << 8 | ((in & 0xFF00) >> 8);
}

void main() {
	int num[] = { 1,257,111,4711 };
	for (int i = 0; i < 4; i++) {
		printf("In: %4d Out: %4d\n", num[i], swap(num[i]));
	}
	system("pause");
}