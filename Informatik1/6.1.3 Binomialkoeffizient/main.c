#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Math.h"


void main() {

	int deph = 15;

	for (int n = 0; n < deph; n++) {
		for (int i = 1; i < (deph-n); i++) {
			printf("   ");
		}
		for (int k = 0; k <= n; k++) {
			printf("%6.0lf", binom(n, k));
		}
		printf("\n");
	}
}