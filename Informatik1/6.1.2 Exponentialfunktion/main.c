#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Math.h"


void main() {
	int x = 5;
	printf("Exp Lib Function: %lf\n", exp(x));
	printf("Potenzreihe exp : %lf\n", partialExp(x, 15));
}