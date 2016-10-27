#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM  20
char Block[DIM][DIM][DIM];
float p = 71.0; //Prozentangabe an Käse

void fillBlock() {
	for (int a = 0; a < DIM; a++) {
		for (int b = 0; b < DIM; b++) {
			for (int c = 0; c < DIM; c++) {
				int r = rand() % 101;
				if (r < p) {
					Block[a][b][c] = '1';
				}
				else {
					Block[a][b][c] = '0';
				}
			}
		}
	}

}


int weg(short x, short y, short z) {
	if (Block[x][y][z] == '.') {
		Block[x][y][z] = '.';
		return 0;
	}
	Block[x][y][z] = '.';
	if (z == DIM - 1) {
		//unten angekommen
		return 1;
	}

	//nach unten
	if (z + 1 < DIM && Block[x][y][z + 1] == '0') {
		if (weg(x, y, z + 1)) {
			return 1;
		}
	}

	//nach rechts
	if (x + 1 < DIM && Block[x + 1][y][z] == '0') {
		if (weg(x + 1, y, z)) {
			return 1;
		}
	}

	//nach links
	if (0 < x && Block[x - 1][y][z] == '0') {
		if (weg(x - 1, y, z)) {
			return 1;
		}
	}

	//nach oben
	if (0 < z && Block[x][y][z - 1] == '0') {
		if (weg(x, y, z - 1)) {
			return 1;
		}
	}

	//nach hinten
	if (0 < y && Block[x][y - 1][z] == '0') {
		if (weg(x, y - 1, z)) {
			return 1;
		}
	}

	//nach vorne
	if (y + 1 < DIM && Block[x][y + 1][z] == '0') {
		if (weg(x, y + 1, z)) {
			return 1;
		}
	}

	return 0;
}

void output() {
	printf("------------------------------\n");
	for (int y = 0; y < 1; y++) {
		for (int z = 0; z < DIM; z++) {
			for (int x = 0; x < DIM; x++) {
				printf("%c ", Block[x][y][z]);
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("------------------------------\n");
}

short search() {
	int ok = 1;
	//Suche an Löchern in der Oberfläche starten
	for (int x = 0; x < DIM; x++) {
		for (int y = 0; y < DIM; y++) {
			if (Block[x][y][0] == '0') {
				if (weg(x, y, 0)) {
					ok = 0;
				}
			}
		}
	}
	return ok == 0;
}

void main() {
	srand(time(NULL));

	int leaks = 0;
	int tests = 10000;
	for (int i = 0; i < tests; i++) {
		fillBlock();
		if (search()) {
			//printf("undicht!!\n");
			leaks++;
		}
		else {
			//printf("dicht!!\n");
		}
	}
	output();
	printf("Käsedichte: %3.2f Prozent\n", p);
	printf("Dicht: %4d (%3.2f Prozent)  Undicht: %4d (%3.2f Prozent)\n", tests - leaks, ((float)tests - leaks) / tests * 100, leaks, ((float)leaks) / tests * 100);
}