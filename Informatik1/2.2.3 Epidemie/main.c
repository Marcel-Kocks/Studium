# include <stdio.h>
# include <stdlib.h>

void main() {
	int gesunde, gesamt, kranke, tage,immune=0;
	float infekt, immunrate;

	printf("Infektionsrate: ");
	scanf_s("%f", &infekt);
	printf("Immunisierungsrate: ");
	scanf_s("%f", &immunrate);
	printf("Gesamtpopulation: ");
	scanf_s("%d", &gesamt);
	printf("Akut Kranke: ");
	scanf_s("%d", &kranke);
	printf("Anzahl Tage: ");
	scanf_s("%d", &tage);
	gesunde = gesamt - kranke;

	for (int i = 1; i <= tage; i++)
	{
		gesunde -= infekt*(gesunde*kranke) / gesamt;
		immune += immunrate*kranke;
		kranke = gesamt - gesunde - immune;
		printf("Tag:%3d Gesunde:%4d Kranke:%4d Immune:%4d\n", i, gesunde, kranke, immune);
	}
}