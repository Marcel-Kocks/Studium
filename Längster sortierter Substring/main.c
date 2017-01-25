#include<stdlib.h>
#include<stdio.h>

int subs(char* s) {
	int count = 0;
	int max = 0;
	char c = 0;
	for (; *s; s++) {
		if (*s>=c) {
			count++;
		}
		else {
			count = 1;
		}
		if (count > max)
			max = count;
		c = *s;
	}
	return max;
}

void main() {
	printf("%d\nr", subs("FACHHOCHSCHULE"));
}