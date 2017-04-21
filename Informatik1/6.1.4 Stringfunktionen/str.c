#include<stdlib.h>

int atoi(const char *string) {
	int erg = 0;
	for (; *string != 0; string++) {
		erg = erg * 10 + (*string - '0');
	}
	return erg;
}

int strcmp(char *str1, char *str2) {
	for (; *str1 != 0 && *str1 == *str2; str1++, str2++)
		;
	return(*str1 - *str2);
}

char * strcat(char *dest, char *src) {
	int len = 0;
	for (int i = 0; dest[i] != 0; i++, len++)
		;
	for (int i = 0; src[i] != 0; i++, len++)
		;
	len++;
	char* erg = (char*)malloc(len * sizeof(char));
	if (!erg)
		return 0;
	int i = 0;
	for (; dest[i] != 0; i++)
		erg[i] = dest[i];
	for (; *src != 0; src++, i++)
		erg[i] = *src;
	erg[i] = 0;
	return erg;
}

char* StrStr(const char *str, const char *target) {
	if (!*target) return str;
	char *p1 = (char*)str, *p2 = (char*)target;
	char *p1Adv = (char*)str;
	while (*++p2)
		p1Adv++;
	while (*p1Adv) {
		char *p1Begin = p1;
		p2 = (char*)target;
		while (*p1 && *p2 && *p1 == *p2) {
			p1++;
			p2++;
		}
		if (!*p2)
			return p1Begin;
		p1 = p1Begin + 1;
		p1Adv++;
	}
	return 0;
}

