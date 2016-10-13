# include <stdio.h>
# include <stdlib.h>


void main()
{
	int StimmenA, StimmenB, StimmenC;
	int sitze;
	int SitzeA, SitzeB, SitzeC;
	int teilerA, teilerB, teilerC;
	int QuotientA, QuotientB, QuotientC;
	int max;

	printf("Stimmen fuer Partei A: ");
	scanf_s("%d", &StimmenA);
	printf("Stimmen fuer Partei B: ");
	scanf_s("%d", &StimmenB);
	printf("Stimmen fuer Partei C: ");
	scanf_s("%d", &StimmenC);
	printf("Gesamtanzahl der Sitze: ");
	scanf_s("%d", &sitze);

	SitzeA = SitzeB = SitzeC = 0;
	teilerA = teilerB = teilerC = 1;
	QuotientA = StimmenA;
	QuotientB = StimmenB;
	QuotientC = StimmenC;

	for (; sitze; sitze = sitze - 1)
	{
		if (QuotientA > QuotientB)
		{
			if (QuotientA > QuotientC)
				max = 1;
			else
				max = 3;
		}
		else
		{
			if (QuotientB > QuotientC)
				max = 2;
			else
				max = 3;
		}

		if (max == 1)
		{
			SitzeA = SitzeA + 1;
			QuotientA = StimmenA / teilerA;
			teilerA = teilerA + 1;
		}
		if (max == 2)
		{
			SitzeB = SitzeB + 1;
			QuotientB = StimmenB / teilerB;
			teilerB = teilerB + 1;
		}
		if (max == 3)
		{
			SitzeC = SitzeC + 1;
			QuotientC = StimmenC / teilerC;
			teilerC = teilerC + 1;
		}
	}

	printf("\nSitzverteilung:\n\n");
	printf("Partei A | Partei B | Partei C\n");
	printf("---------+----------+---------\n");
	printf("  %3d    |   %3d    |  %3d\n\n", SitzeA, SitzeB, SitzeC);
}
