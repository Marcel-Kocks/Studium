#include<stdlib.h>
#include<stdio.h>

double Mittelwert(int* dataStart, int* dataEnd) {
	double erg = 0;
	int lengh = dataEnd - dataStart;
	for (; dataStart <= dataEnd; dataStart++) {
		erg += *dataStart;
	}
	return erg / lengh;
}

double Varianz(int* dataStart, int* dataEnd) {
	double mw = Mittelwert(dataStart, dataEnd);
	double erg = 0;
	for (; dataStart <= dataEnd; dataStart++) {
		erg += (*dataStart - mw) * (*dataStart - mw);
	}
	return erg;
}

void main() {
	int data[] = { 4,5,6,5,3,5,6,3,5,4,5,4,4,6,6,4 };

	printf("Mittelwert: %lf\n", Mittelwert(data, data + 15));
	printf("Varianz: %lf\n", Varianz(data, data + 15));
}