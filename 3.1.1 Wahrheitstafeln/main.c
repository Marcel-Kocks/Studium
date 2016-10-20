# include <stdio.h>
# include <stdlib.h>

void main() {

	printf("| A | B | C | D || 1 || 2 || 3 || 4 ||\n");
	printf("|---|---|---|---||---||---||---||---||\n");

	for (short a = 0; a < 2; a++) {
		for (short b = 0; b < 2; b++) {
			for (short c = 0; c < 2; c++) {
				for (short d = 0; d < 2; d++) {
					short e1 = !(a&&b)||(c||d);
					short e2 = (!((!(a&&b))||c))&&d;
					short e3 = 0;
					short e4 = 0;
					printf("| %1d | %1d | %1d | %1d || %1d || %1d || %1d || %1d ||\n",a,b,c,d,e1,e2,e3,e4);
				}
			}
		}
	}
}