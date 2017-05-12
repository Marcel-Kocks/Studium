// 4.1.1 Klasse mystring.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "myString.h"

using namespace std;

int main()
{
	myString test = myString("Hallo");
	myString marc = myString("Marcel");

	test += marc;

	test = test;

	test += "hi";

	marc + test;

	cout << "TEST: " << test << marc << endl;
	cout << "Equal? :" << (test == marc) << endl;

	system("PAUSE");
    return 0;
}

