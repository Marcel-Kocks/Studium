# include <stdio.h>
# include <stdlib.h>

void myprintf(char *fmt, ...)
{
	int *p;

	p = (int *) &fmt; //Pointer to PointerObject on Stack

	for (; *fmt; fmt++)
	{
		if (*fmt != '#')
			printf("%c", *fmt);
		else
			printf("%d", *++p);
	}
}

void main()
{
	int a = 123;
	int b = 456;
	myprintf("Test: # + # ist #\n", a, b, a + b);
}
