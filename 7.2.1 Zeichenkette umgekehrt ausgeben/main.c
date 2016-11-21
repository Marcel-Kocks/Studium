#include <stdlib.h>
#include <stdio.h>

void reverse(char* str,int len) {
	if (len <= 1) {
		return;
	}
	char c = str[0];
	str[0] = str[len - 1];
	str[len - 1] = c;
	reverse(++str, len - 2);
}

void main() {
	char in[] = "InputString";
	int i = 0;
	for (; *(in + i) != 0; i++)
		;
	reverse(in, i);

	printf("%s\n", in);
}