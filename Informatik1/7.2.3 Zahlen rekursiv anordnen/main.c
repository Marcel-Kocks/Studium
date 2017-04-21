#include<stdlib.h>
#include<stdio.h>

void doIT(int* start, int* end) {
	if (start >= end)
		return;
	if (*start < 0)
		doIT(++start, end);
		return;
		if (*end > 0)
			doIT(start, --end);
			return;
	int c = *start;
	*start = *end;
	*end = c;
	doIT(++start, --end);
	return;
}

void main() {
	int num[5] = { 6,-7,3,-3,-2 };
	doIT(num, num + 4);

	for (int i = 0; i < 5; i++) {
		printf("%d\n", num[i]);
	}
}