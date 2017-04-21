#include<stdio.h>

int add(int anzahl, ...) {
	int erg = 0;
	for (; anzahl >= 1; anzahl--) {
		erg += *(&anzahl + anzahl);
	}
	return erg;
}

void main() {
	int x;
	x = add(5, 1, 2, 3, 4, 5);
	printf("%d\n", x);
}