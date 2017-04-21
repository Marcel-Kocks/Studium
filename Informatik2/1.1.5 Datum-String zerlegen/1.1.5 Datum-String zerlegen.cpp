// 1.1.5 Darum-String zerlegen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


struct Datum {
	int Tag;
	int Monat;
	int Jahr;
};

Datum StringToDate(char * str) {
	Datum date;
	date.Tag = *str -'0';
	date.Tag *= 10;
	str++;
	date.Tag += *str - '0';

	str++;
	str++;

	date.Monat = *str - '0';
	date.Monat *= 10;
	str++;
	date.Monat += *str - '0';

	str++;
	str++;

	date.Jahr = *str - '0';
	date.Jahr *= 10;
	str++;
	date.Jahr += *str - '0';
	date.Jahr *= 10;
	str++;
	date.Jahr += *str - '0';
	date.Jahr *= 10;
	str++;
	date.Jahr += *str - '0';

	return date;
}

char * toString(Datum date, char * out) {
	out = (char*)malloc(10 * sizeof(char));

	out[0] = '0' + date.Tag / 10;
	out[1] = '0' + date.Tag - 10*(date.Tag / 10);

	out[2] = '.';

	out[3]= '0' + date.Monat / 10;
	out[4] = '0' + date.Monat - 10 * (date.Monat / 10);

	out[5] = '.';

	out[6] = '0' + date.Jahr / 1000;
	out[7] = '0' + (date.Jahr - 1000 * (date.Jahr / 1000)) / 100;
	out[8] = '0' + (date.Jahr - 1000 * (date.Jahr / 1000) - 100 * ((date.Jahr - 1000 * (date.Jahr / 1000)) / 100)) / 10;
	out[9] = '0' + (date.Jahr - 1000 * (date.Jahr / 1000) - 100 * ((date.Jahr - 1000 * (date.Jahr / 1000)) / 100) - 10 * ((date.Jahr - 1000 * (date.Jahr / 1000) - 100 * ((date.Jahr - 1000 * (date.Jahr / 1000)) / 100)) / 10));

	return out;
}

void print(Datum date) {
	printf("%d.%d.%d", date.Tag, date.Monat, date.Jahr);
}

Datum operator+(Datum date, int AnzahlTage) {
	Datum out;
	out.Tag = date.Tag + AnzahlTage;
	out.Monat = date.Monat;
	out.Jahr = date.Jahr;

	for (; out.Tag > 30;) {
		out.Tag -= 30;
		out.Monat++;
	}

	for (; out.Monat > 12;) {
		out.Monat -= 12;
		out.Jahr++;
	}
	return out;
}


int operator>(Datum a,Datum b) {
	if (a.Jahr > b.Jahr)
		return 1;
	if (a.Jahr < b.Jahr)
		return 0;

	if (a.Monat > b.Monat)
		return 1;
	if (a.Monat < b.Monat)
		return 0;

	if (a.Tag > b.Tag)
		return 1;
	return 0;
}

int operator- (Datum a, Datum b) {
	bool inverse = false;

	if (a > b) {
		inverse = true;
		Datum c = a;
		a = b;
		b = c;
	}

	int i = 0;
	for (; b > a; i++) {
		a = a + 1;
	}

	return inverse ? i : -1 * i;
}



int main()
{
	Datum von = StringToDate("15.11.1996");
	Datum nach = StringToDate("21.04.2017");
	
	int hi = nach - von;


	char out[10];
	toString(von,out);
	print(nach + 15);
	printf("\n");

	system("PAUSE");
    return 0;
}

