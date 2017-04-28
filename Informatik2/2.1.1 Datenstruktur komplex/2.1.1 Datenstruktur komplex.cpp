// 2.1.1 Datenstruktur komplex.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "2.1.1 Datenstruktur komplex.h"

komplex komp_init(double real, double img) {
	komplex ret;
	ret.img = img;
	ret.real = real;
	return ret;
}

int komp_equal(komplex a, komplex b) {
	if(a.real != b.real) 
		return 0;
	if (a.img != b.img)
		return 0;
	return 1;
}

double komp_abs(komplex k)
{
	return sqrt(k.img*k.img + k.real*k.real);
}

komplex komp_add_kk(komplex& a, komplex& b)
{
	komplex erg;
	erg.img = a.img + b.img;
	erg.real = a.real + b.real;
	return erg;
}

komplex komp_add_kr(komplex a, double b)
{
	a.real + b;
	return a;
}

komplex komp_mult_kk(komplex& a, komplex& b)
{
	komplex ret;
	ret.real = a.real*b.real - a.img*b.img;
	ret.img = a.real*b.img + a.img*b.real;
	return ret;
}

komplex komp_mult_kr(komplex a, double b)
{
	a.img *= b;
	a.real *= b;
	return a;
}

komplex komp_div_kk(komplex a, komplex b)
{
	komplex erg;
	erg.real = (a.real *b.real + a.img*b.img) / (b.real*b.real + a.img*a.img);
	erg.img = (a.img*b.real - a.real*b.img) / (b.real*b.real + a.img*a.img);
	return erg;
}

komplex komp_div_kr(komplex a, double b)
{
	return komp_div_kk(a,komp_init(b,0));
}


int main()
{
	using std::cout;
	cout << komp_abs(komp_init(5,5));
	system("PAUSE");
    return 0;
}

