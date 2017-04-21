#include <stdlib.h>
#include <stdio.h>

int zug(int Feld[8][8], int Zug, int StartX, int StartY, int ZielX, int ZielY) {
	if (StartX < 0 || StartX >= 8 || StartY < 0 || StartY >= 8 || Feld[StartX][StartY] != 0) {
		return 0;
	}
	Zug++;
	if (StartX == ZielX && StartY == ZielY) {
		Feld[StartX][StartY] = Zug;
		return 1;
	}
	int min = 999;

	for (int x = -2; x <= 2; x++) {
		if (x == 0)
			continue;
		for (int y = -2; y <= 2; y++) {
			if (y == 0 || x*x == y*y)
				continue;
			Feld[StartX][StartY] = Zug;
			int z = zug(Feld, Zug, StartX + x, StartY + y, ZielX, ZielY);
			printf("x=%2d y=%2d z=%2d\n", StartX + x, StartY + y, z);
			if (z < min && z != 0) {
				min = z;
				return ++z;
			}
			else {
				Feld[StartX][StartY] = 0;
			}
		}
	}
	Feld[StartX][StartY] = 0;
	return 0;
}

void ausgabe(int Feld[8][8]) {
	printf("+--+--+--+--+--+--+--+--+\n");
	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			if (Feld[x][y] > 0)
				printf("|%2d", Feld[x][y]);
			else
				printf("|  ");
		}
		printf("|\n");
		printf("+--+--+--+--+--+--+--+--+\n");
	}
} 

void main() {
	int Feld[8][8];
	int StartX = 0;
	int StartY = 0;
	int ZielX = 0;
	int ZielY = 1;

	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			Feld[x][y] = 0;
		}
	}
	zug(Feld, 0, StartX, StartY, ZielX, ZielY);
	ausgabe(Feld);
	scanf_s("");
}