#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<stdio.h>
#include "main.h"


struct Station
{
	int id;
	char name[26];
};

struct Datum
{
	int tag;
	int monat;
	int jahr;
};

struct Messdaten
{
	struct Datum dat;
	float min5cm;
	float min2m;
	float mittel2m;
	float max2m;
	float relfeuchte;
	float maxwindg;
	float sonnenschein;
	float mittelbedeckt;
	float niederschlag;
	float mittelluftdruck;
	int id;
	int qualitaet;
	int mittelwindst;
};

struct SearchQuery
{
	int id;
	struct Datum dat;
};


struct Station wetterstationen[77];

void importStationen(FILE *pfile) {
	struct Station* tmp = wetterstationen;
	for (int i = 0; !feof(pfile) && i < 77; i++) {
		fscanf(pfile, "%d;%s", &(tmp->id), &(tmp->name));
		tmp++;
	}
}


void importData() {
	FILE *pf;
	pf = fopen("Wetterstationen.txt", "r");
	if (!pf)
		return;
	importStationen(pf);
	fclose(pf);
}

void outputStations() {
	for (int i = 0; i < 77; i++) {
		printf("%d:  %s\n", wetterstationen[i].id, wetterstationen[i].name);
	}
}

struct SearchQuery* input() {
	struct SearchQuery* pOut = (struct SearchQuery*) malloc(sizeof(struct SearchQuery));
	printf("\n\nGib ID ein: ");
	scanf("%d", &(pOut->id));
	printf("\nGib ein Datum ein (tt.mm.jjjj): ");
	scanf("%d.%d.%d", &(pOut->dat.tag), &(pOut->dat.monat), &(pOut->dat.jahr));

	return pOut;
}


int anfrage(struct SearchQuery s, struct Messdaten *pmd)
{
	FILE *pf;

	pf = fopen("Wettermessungen.txt", "r");
	for (; ;)
	{
		fscanf(pf, "%d;%d.%d.%d;%d;%f;%f;%f;%f;%f;%d;%f;%f;%f;%f;%f", &pmd->id,
			&pmd->dat.tag,
			&pmd->dat.monat,
			&pmd->dat.jahr,
			&pmd->qualitaet,
			&pmd->min5cm,
			&pmd->min2m,
			&pmd->mittel2m,
			&pmd->max2m,
			&pmd->relfeuchte,
			&pmd->mittelwindst,
			&pmd->maxwindg,
			&pmd->sonnenschein,
			&pmd->mittelbedeckt,
			&pmd->niederschlag,
			&pmd->mittelluftdruck);
		if (feof(pf))
			break;
		if ((pmd->id == s.id) && (s.dat.tag == pmd->dat.tag) && (s.dat.monat == pmd->dat.monat) && (s.dat.jahr == pmd->dat.jahr))
		{
			fclose(pf);
			return 1;
		}
	}
	fclose(pf);
	return 0;
}

void ausgabe(struct Messdaten *pmd)
{
	int i;

	printf("\nStation:                      %5d ", pmd->id);
	for (i = 0; i < 77; i++)
	{
		if (wetterstationen[i].id == pmd->id)
			printf("%s", wetterstationen[i].name);
	}
	printf("\n");
	printf("Datum:                        %d.%d.%d\n", pmd->dat.tag, pmd->dat.monat, pmd->dat.jahr);
	printf("Qualitaet:                    %5d\n", pmd->qualitaet);
	printf("Min 5cm:                      %5.1f\n", pmd->min5cm);
	printf("Min 2m:                       %5.1f\n", pmd->min2m);
	printf("Mittel 2m:                    %5.1f\n", pmd->mittel2m);
	printf("Max 2m:                       %5.1f\n", pmd->max2m);
	printf("Relative Feuchte:             %5.1f\n", pmd->relfeuchte);
	printf("Mittlere Windstaerke:         %5d\n", pmd->mittelwindst);
	printf("Maximale Windgeschwindigkeit: %5.1f\n", pmd->maxwindg);
	printf("Sonnenschein:                 %5.1f\n", pmd->sonnenschein);
	printf("Mittlerer Bedeckungsgrad:     %5.1f\n", pmd->mittelbedeckt);
	printf("Niederschlagshoehe:           %5.1f\n", pmd->niederschlag);
	printf("Mittlerer Luftdruck:          %5.1f\n", pmd->mittelluftdruck);
}

void main() {
	importData();
	outputStations();

	struct SearchQuery* q = input();

	struct Messdaten md;

	if (anfrage(*q, &md))
		ausgabe(&md);

	system("PAUSE");
}
