# include <stdio.h>
# include <stdlib.h>

void main() {
#define DIM 5

	//BULLSHIT

	int Feld[DIM][DIM];

	char inputString[DIM * 3 + 1] = "";
	char inputSet[] = "%d ";
	for (int i = 0; i < DIM; i++) {
		strcat(inputString, inputSet);
	}
	printf(inputString);

	int input;
	scanf_s("%d ",&input);
	printf("%d", input);
	
}