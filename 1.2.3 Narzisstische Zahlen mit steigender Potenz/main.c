#include <stdio.h>
#include <stdlib.h>

int hoch(int x, int n)
{
	int erg = x;
	for (; n > 1; n--) {
		erg *= x;
	}
	return erg;
}

void main() {

	for (int a = 1; a < 10; a++)
	{
		for (int b = 0; b < 10; b++)
		{
			for (int c = 0; c < 10; c++)
			{
				int z = 100 * a + 10 * b + c;
				int sum = 0;

				sum += hoch(a, 1);
				sum += hoch(b, 2);
				sum += hoch(c, 3);

				if (z == sum) {
					printf("%d\n", z);
				}
			}
		}
	}
}