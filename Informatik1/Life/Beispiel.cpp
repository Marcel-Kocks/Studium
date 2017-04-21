# include "Igel.h"

# define MAXZ           60
# define MINZ           10
# define MAXS          100
# define MINS           10
# define FELDGROESSE    12

static int akt[MAXZ][MAXS];
static int tmp[MAXZ][MAXS];
int zeilen;
int spalten;
int zeit;

static void setze(int z, int s, COLORREF c)
{
	rectangle((s + 1)*FELDGROESSE, (z + 1)*FELDGROESSE, (s + 2)*FELDGROESSE, (z + 2)*FELDGROESSE, 1, RGB(0, 0, 0), c);
}

static void aktualisieren()
{
	int i, j;

	for (i = 0; i < zeilen; i++)
	{
		for (j = 0; j < spalten; j++)
		{
			if (akt[i][j] != tmp[i][j])
			{
				akt[i][j] = tmp[i][j];
				setze(i, j, akt[i][j] ? RGB(0, 255, 0) : RGB(255, 255, 255));
			}
		}
	}
}

static void zyklus()
{
	int i, j;
	int p, q;
	int s;

	for (i = 0; i < zeilen; i++)
	{
		for (j = 0; j < spalten; j++)
		{
			s = 0;
			for (p = i - 1; p <= i + 1; p++)
			{
				for (q = j - 1; q <= j + 1; q++)
					s += akt[(p + zeilen) % zeilen][(q + spalten) % spalten];
			}
			tmp[i][j] = ((s - akt[i][j] == 3) || (s == 3));
		}
	}
	aktualisieren();
}

static void setup()
{
	int i, j, f;
	int z, s;
	int evt;

	for (i = 0; i < zeilen; i++)
	{
		for (j = 0; j < spalten; j++)
		{
			akt[i][j] = tmp[i][j] = 0;
			setze(i, j, RGB(255, 255, 255));
		}
	}
	for (; ;)
	{
		evt = mouse_event(&f, &i, &j, 1);
		if (evt == WM_LBUTTONDOWN)
		{
			s = i / FELDGROESSE - 1;
			z = j / FELDGROESSE - 1;
			if ((z >= 0) && (z<zeilen) && (s >= 0) && (s<spalten))
			{
				tmp[z][s] = !tmp[z][s];
				setze(z, s, tmp[z][s] ? RGB(255, 0, 0) : RGB(255, 255, 255));
			}
		}
		if (evt == WM_RBUTTONDOWN)
		{
			if (select(2, "Eingabe fortsetzen", "Eingabe beenden") == 2)
				break;
		}
	}
	aktualisieren();
}

void IgelMain()
{
	show_console();
	printf("Anzahl Zeilen: ");
	scanf("%d", &zeilen);
	printf("\r\n");
	if ((zeilen < MINZ) || (zeilen > MAXZ))
		zeilen = MAXZ;

	printf("Anzahl Spalten: ");
	scanf("%d", &spalten);
	printf("\r\n");
	if ((spalten < MINS) || (spalten > MAXS))
		spalten = MAXS;

	printf("Wartezeit in ms: ");
	scanf("%d", &zeit);
	if (zeit < 0)
		zeit = 0;
	hide_console();

	setup();
	for (; ;)
	{
		zyklus();
		wait(zeit);
	}
}