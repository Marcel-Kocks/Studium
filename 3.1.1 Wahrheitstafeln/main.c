# include <stdio.h>
# include <stdlib.h>

void main() {

	printf("1: !(a&&b)||(c||d)\n");
	printf("2: (!((!(a&&b))||c))&&d\n");
	printf("3: !(!(!a||b))||(c||!d)\n");
	printf("4: (a||!b)&&!((a||c)&&d)\n\n");

	printf("| A | B | C | D || 1 || 2 || 3 || 4 ||\n");
	printf("|---|---|---|---||---||---||---||---||\n");

	for (short a = 0; a < 2; a++) {
		for (short b = 0; b < 2; b++) {
			for (short c = 0; c < 2; c++) {
				for (short d = 0; d < 2; d++) {
					short e1 = !(a&&b)||(c||d);
					short e2 = (!((!(a&&b))||c))&&d;
					short e3 = !(!(!a||b))||(c||!d);
					short e4 = (a||!b)&&!((a||c)&&d);
					printf("| %1d | %1d | %1d | %1d || %1d || %1d || %1d || %1d ||\n",a,b,c,d,e1,e2,e3,e4);
				}
			}
		}
	}
}