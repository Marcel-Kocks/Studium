#include<stdlib.h>
#include<stdio.h>

void Kaffee(int Minute, float t, float s) {
	printf("Minute: %3d Raum: %3.3f Tasse: %3.3f\n", Minute, s, t);
	if ((t - s) <= 0.1)
		return;
	Kaffee(Minute + 1, t - (t - s)*0.05, s);
}

void main() {
	Kaffee(0, 500, 20);
	system("pause");
}