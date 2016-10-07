# include <stdio.h>
# include <stdlib.h>

void main() {
	float a, b, c, f;

	printf("1. Zahl: ");
	scanf_s("%f", &a);

	printf("2. Zahl: ");
	scanf_s("%f", &b);

	printf("3. Zahl: ");
	scanf_s("%f", &c);

	if (a > b) {

	}
	else {
		f = a;
		a = b;
		b = f;
	}

	//a > b

	if (a > c) {

	}
	else {
		f = a;
		a = c;
		c = f;
	}

	//a = max

	if (b > c) {

	}
	else {
		f = b;
		b = c;
		c = f;
	}

	//b=2. c=3.

	printf("\n%f\n%f\n%f\n", a, b, c);

}