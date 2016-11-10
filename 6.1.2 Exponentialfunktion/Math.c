#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Math.h"

double partialExp(double x, int n)
{
	double erg = 0;
	for (; n >= 0; n--) {
		erg += pow(x, n) / fac(n);
	}
	return erg;
}

double fac(int x)
{
	double erg = 1;
	for (; x > 0; x--) {
		erg *= x;
	}
	return erg;
}
