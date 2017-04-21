#include <stdio.h>
#include <stdlib.h>


int count(char* data,char let) {
	int res = 0;
	for (; *data != 0; data++) {
		if (*data == let) {
			res++;
		}
	}
	return res;
}
void main() {
	char string[100];
	char let;
	
	printf("Wort zum zählen eingeben: ");
	scanf_s("%s", &string);
	
	printf("Zu zählender Buchstabe?: ");
	scanf_s("\n%c", &let);

	printf("Der Buchstabe %c kommt %d -mal im Wort \"%s\" vor.", let, count(string, let), string);

}