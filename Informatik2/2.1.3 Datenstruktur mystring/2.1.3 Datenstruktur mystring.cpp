// 2.1.3 Datenstruktur mystring.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "mystring.h"


int main()
{
	mystring* test = str_create();
	str_set(test, "TEST");

	mystring* hallo = str_create();
	str_set(hallo, "hallo");

	//str_insert(test, hallo, 3);
	str_add(test, hallo);
	printf("%s\n", str_get(test));
	system("PAUSE");
    return 0;
}

