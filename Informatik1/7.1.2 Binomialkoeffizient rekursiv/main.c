#include <stdlib.h>
#include <stdio.h>

int binom(int n, int k) {
	if (n == k || k == 0) {
		return 1;
	}
	else {
		return binom(n - 1, k) + binom(n - 1, k - 1);
	}
	/*if (n > k && k > 0) {
		return binom(n - 1, k) + binom(n - 1, k - 1);
	}
	else {
		return 1;
	}*/
}

void main() {

	int deph = 15;

	for (int n = 0; n < deph; n++) {
		for (int i = 1; i < (deph - n); i++) {
			printf("   ");
		}
		for (int k = 0; k <= n; k++) {
			printf("%6d", binom(n, k));
		}
		printf("\n");
	}
}