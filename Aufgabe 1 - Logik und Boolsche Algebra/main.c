#include<stdlib.h>
#include<stdio.h>

void main() {
	int total = 0;
	int hit = 0;

	for (int s1 = 0; s1 <= 1; s1++) {
		for (int s2 = 0; s2 <= 1; s2++) {
			for (int s3 = 0; s3 <= 1; s3++) {
				for (int s4 = 0; s4 <= 1; s4++) {
					for (int s5 = 0; s5 <= 1; s5++) {
						total++;
						if (!s1)
							continue;
						if (s2) {
							hit++;
							continue;
						}
						if (!s3)
							continue;
						if (s4 || s5) {
							hit++;
						}
					}
				}
			}
		}
	}
	printf("Wahrscheinlichkeit: %2.1f Prozent\n", (hit * 100.0) / total);
	system("PAUSE");
}