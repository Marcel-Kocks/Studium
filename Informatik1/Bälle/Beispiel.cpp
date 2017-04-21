# include "Igel.h"

# define SEGMENTE 5

void ball(int min, int max)
{
	int i, x, y, mx, my, s, r;

	get_windowsize(&mx, &my);
	x = rand() % mx;
	y = rand() % my;
	s = min + rand() % (max - min + 1);

	for (i = 0; i <= SEGMENTE; i++)
	{
		r = s - (i*(s - s / (2 * SEGMENTE))) / SEGMENTE;
		ellipse(x - r, y - s, x + r, y + s, 1, RGB(0, 0, 0), RGB(rand() % 256, rand() % 256, rand() % 256));
	}
}

void IgelMain()
	{
	int anzahl, min, max, zf;
	int i;

	show_console();
	printf( "Anzahl Baelle: ");
	scanf( "%d", &anzahl);
	printf("\r\n");
	printf( "minimaler Radius: ");
	scanf( "%d", &min);
	printf("\r\n");
	printf( "maximaler Radius: ");
	scanf( "%d", &max);
	printf("\r\n");
	printf( "Startwert ZF-Generator: ");
	scanf( "%d", &zf);
	printf("\r\n");
	hide_console();

	srand( zf);

	for( i = 0; i < anzahl; i++)
		ball( min, max);
	}