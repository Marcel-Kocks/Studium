#include <stdio.h>
#include <stdlib.h>

int checkForPali(char* pvorne) {
	char* phinten = pvorne;
	for (; *phinten != 0; phinten++)
		continue;
	phinten--;
	for (; phinten > pvorne; phinten--, pvorne++) {
		if ((*phinten | 1 << 5) != (*pvorne | 1 << 5)) { //5th bit == capital | small initial letter
			break;
		}
	}
	return (*phinten == *pvorne);
}

void main() {
	char string[] = "Otto";

	if (checkForPali(string)) {
		printf("JA\n");
	}
	else
	{
		printf("NEIN\n");
	}
}