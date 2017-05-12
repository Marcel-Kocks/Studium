#pragma once

#include <ostream>

using namespace std;

class myString
{
	friend ostream& operator<< (ostream& os, const myString&  s);


private:
	int length; // Laenge des gespeicherten Strings
	char* data; // Zeiger auf den Buffer

public:
	myString(); // Parameterloser Konstruktor
	myString(char* t); //  Konstruktor mit Text
	~myString(); // Destruktor
	myString(const myString& s);  // Copy-Konstruktor

	myString& myString::operator=(const char* s);  // Zuweisungsoperator
	myString& myString::operator=(const myString& s);  // Zuweisungsoperator


	myString myString::operator+(const myString& s);// Additionsoperator
	myString& myString::operator+=(const myString& rhs);  // Addition und Zuweisung

	bool myString::operator==(const myString& rhs);

	bool myString::operator<(const myString& rhs);
	bool myString::operator>(const myString& rhs);

	bool myString::operator<=(const myString& rhs);
	bool myString::operator>=(const myString& rhs);
												//... Weitere Methoden
};
