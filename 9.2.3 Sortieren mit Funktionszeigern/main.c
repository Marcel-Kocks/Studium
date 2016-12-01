#include<stdio.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void sort(int* dataStart, int* dataEnd, int comp(int, int)) {
	int *ptr;
	int *split;
	if (dataEnd - dataStart <= 1)
		return;
	ptr = dataStart;
	split = dataStart + 1;
	while (++ptr <= dataEnd) {
		if (comp(*ptr, *dataStart)) {
			swap(ptr, split);
			++split;
		}
	}
	swap(dataStart, split - 1);
	sort(dataStart, split - 1, comp);
	sort(split, dataEnd, comp);
}

int gr(int a, int b) {
	return a > b;
}

int kl(int a, int b) {
	return a < b;
}

void ausgabe(int anz, int *a, char *txt)
{

	printf("\n%-12s: ", txt);
	for (; anz; anz--, a++)
		printf("%3d", *a);
}

void main()
{
	int a[20] = { 17,14,3,20,5,11,7,13,19,10,6,16,8,2,15,12,1,18,9,4 };

	ausgabe(20, a, "Vorher");
	sort(a, a + 19, gr);
	ausgabe(20, a, "Aufsteigend");
	sort(a, a + 19, kl);
	ausgabe(20, a, "Absteigend");
	printf("\n");
}
