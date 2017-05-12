// 3.2.3 Erweiterte Klasse datum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Date.h"


int main()
{
	Date* test = new Date(15, 5, 1997);
	printf("%s\n", test->toString());
	

	printf("%s\n", test->WochentagToString(Date::Wochentag(4)));
	system("PAUSE");
    return 0;
}

