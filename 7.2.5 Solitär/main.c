# include <stdio.h>
# include <stdlib.h>

int brett[7][7] =
{
	{ -1, -1,  1,  1,  1, -1, -1 },
	{ -1, -1,  1,  1,  1, -1, -1 },
	{ 1,  1,  1,  1,  1,  1,  1 },
	{ 1,  1,  1,  0,  1,  1,  1 },
	{ 1,  1,  1,  1,  1,  1,  1 },
	{ -1, -1,  1,  1,  1, -1, -1 },
	{ -1, -1,  1,  1,  1, -1, -1 }
};

int zug[4][2] = { { 2,0 },{ -2,0 },{ 0,2 },{ 0,-2 } };

int solitaer(int tiefe)
{
	int z_start, s_start, z_ziel, s_ziel, z_zwischen, s_zwischen;
	int versuch;

	if (tiefe == 31)
		return brett[3][3];
	for (z_start = 0; z_start < 7; z_start++)
	{
		for (s_start = 0; s_start < 7; s_start++)
		{
			if (brett[z_start][s_start]> 0)
			{
				for (versuch = 0; versuch < 4; versuch++)
				{
					z_ziel = z_start + zug[versuch][0];
					if ((z_ziel < 0) || (z_ziel >= 7))
						continue;
					s_ziel = s_start + zug[versuch][1];
					if ((s_ziel < 0) || (s_ziel >= 7))
						continue;
					z_zwischen = (z_start + z_ziel) / 2;
					s_zwischen = (s_start + s_ziel) / 2;
					if (brett[z_zwischen][s_zwischen] && !brett[z_ziel][s_ziel])
					{
						brett[z_start][s_start] = 0;
						brett[z_zwischen][s_zwischen] = 0;
						brett[z_ziel][s_ziel] = 1;
						if (solitaer(tiefe + 1))
						{
							printf("%2d: (%d,%d)->(%d,%d)\n", tiefe + 1, z_start, s_start, z_ziel, s_ziel);
							return 1;
						}
						brett[z_start][s_start] = 1;
						brett[z_zwischen][s_zwischen] = 1;
						brett[z_ziel][s_ziel] = 0;
					}
				}
			}
		}
	}
	return 0;
}

void main()
{
	solitaer(0);
}
