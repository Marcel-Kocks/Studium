// 7.1.1 Vervollständigung einer Klasse.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class speicher
{
public:
	char c;
	speicher(char init) { c = init; };
};

class meinspeicher : public speicher
{
public:
	meinspeicher(char basis, char embed) :speicher(basis)
	{ 
		pointer = new speicher(embed); 
	}

	meinspeicher(const meinspeicher &cpy) :speicher(cpy.c) 
	{ 
		pointer = new speicher(cpy.pointer->c); 
	}

	~meinspeicher()
	{
		delete pointer;
	}
private:
	speicher *pointer;
};




int main()
{
    return 0;
}

