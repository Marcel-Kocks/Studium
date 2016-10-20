# include <stdio.h>
# include <stdlib.h>

void main() {

	printf(" A | B | C | D || log1");

	for (short a = 0; a < 2; a++) {
		for (short b = 0; b < 2; b++) {
			for (short c = 0; c < 2; c++) {
				for (short d = 0; d < 2; d++) {
					printf(" %d | %d | %d | %d || ");
				}
			}
		}
	}
}