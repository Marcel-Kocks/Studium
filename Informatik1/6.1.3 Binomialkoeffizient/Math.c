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

double parFac(int from, int to) {
	double erg = 1;
	for (; to > from; to--) {
		erg *= to;
	}
	return erg;
}

double binom(int n, int k) {
	double erg = 0;
	erg = parFac(k, n) / fac(n - k);
	return erg;
}
