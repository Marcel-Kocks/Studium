#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define SYSTEM 2

void dual(unsigned int z, char *s) {
	for (; z; z /= SYSTEM) {
		*s = '0' + z%SYSTEM;
		s++;
	}
	*s = 0;
}

void revert(char *start) {
	char* end = start;
	for (; *end; end++)
		continue;
	end--;

	while (start < end) {
		char c = *end;
		*end = *start;
		*start = c;

		start++;
		end--;
	}
}

void main() {
	char str[100];
	dual(553252, str);
	revert(str);
	printf("%s\n", str);
	system("pause");
}