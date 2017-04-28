// 1.1.6 String vervielfachen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void strmult(int a, char *s) {
	int lengh = strlen(s);
	char * templ = (char *)malloc(lengh *sizeof(char));

	strcpy_s(templ, lengh+1, s);

	for (int i = 1; i < a; i++) {
		s = s + lengh;
		strcpy_s(s, lengh+1,templ);
		
	}
}

int main()
{
	char text[100] = "Hallo";
	strmult(4, text);
	 
	printf("%s\n",text);
	system("PAUSE");
    return 0;
}

