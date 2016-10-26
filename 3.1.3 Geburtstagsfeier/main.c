# include <stdio.h>
# include <stdlib.h>

void main() {

	for (int a = 0; a < 2; a++)
	{
		for (int b = 0; b < 2; b++)
		{
			for (int c = 0; c < 2; c++)
			{
				for (int d = 0; d < 2; d++)
				{
					if (a || b || c || d) {
						if (!(a&&d)) {
							if (!b || c) {
								if (!a || !c || !b) {
									if (a || (c != d)) {
										printf("Anton=%d Berta=%d Claus=%d Doris=%d\n", a, b, c, d);
									}
								}
							}
						}
					}
				}
			}
		}
	}
}