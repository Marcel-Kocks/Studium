#include<stdio.h>

void arrayoperation(int* out, int anz, int* in1, int* in2, int fkt(int, int)) {
	for (; anz; anz--, out++, in1++, in2++) {
		*out = fkt(*in1, *in2);
	}
}

int add(int a, int b)
{
	return a + b;
}

int mod(int a, int b)
{
	return a%b;
}

int sub(int a, int b)
{
	return a - b;
}

void ausgabe(int anz, int *a, char *txt)
{

	printf("\n%-10s: ", txt);
	for (; anz; anz--, a++)
		printf("%3d", *a);
}

void main()
{
	int a[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,20 };
	int b[20] = { 21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40 };
	int c[20];

	ausgabe(20, a, "a");
	ausgabe(20, b, "b");
	arrayoperation(c, 20, a, b, add);
	ausgabe(20, c, "c = a+b");
	arrayoperation(c, 20, b, a, mod);
	ausgabe(20, c, "c = b%a");
	arrayoperation(c, 20, a, c, sub);
	ausgabe(20, c, "c = a-c");
	printf("\n");
}