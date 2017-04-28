#pragma once

struct mystring
{
	char* str;
};


mystring * str_create();
//Legt einen leeren String an.

void str_destroy(mystring *s);
//Beseitigt einen mit str_create angelegten String s.

void str_set(mystring *s, char *buf);
//Kopiert den im Buffer buf (0-terminiert) uebergebene n Inhalt in den Strings.

const char *str_get(mystring *s);
//Liefert (z.B. fuer Ausgabezwecke) einen konstanten Zeiger auf die interne Zeichenkette.

void str_add(mystring *s, mystring *t);
//Fuegt den String t an den String s an.

void str_insert(mystring *s, mystring *t, int pos);
//Fuegt den String t an der Position pos in den String sein, sofern es sich um eine vernuenftige Positionsangabe handelt.

int str_length(mystring *s);
//Liefert die Laenge des Strings s. Ein leerer String wird an der Laenge 0 erkannt.

int str_test(mystring *s, mystring *t);
//‹berprueft, ob der String t im String s vorkommt und gibt entsprechend 1 oder 0 zurueck.

int str_compare_cs(mystring *s, mystring *t);
//Vergleicht die beiden Strings s und t case-sensitive, d.h. mit Beruecksichtigung von Gross - und Kleinschreibung. Gibt bei Gleichheit 1 bei Ungleichheit 0 zurueck.
int str_compare_cis(mystring *s, mystring *t);
//Vergleicht die beiden Strings s und tcase-insensitive, d.h. ohne Beruecksichtigung von Gross- und Kleinschreibung. Gibt bei Gleichheit 1 bei Ungleichheit 0 zurueck.

void str_extract(mystring *s, mystring *t, int from, int to);
//Extrahiert den Teilstring von from bis to aus dem String s, sofern es sich bei from und to um vernuenftige Positionsangaben handelt, und kopiert diesen Teilstring in den String t.

void str_setchar(mystring *s, int pos, char c);
//Setzt den Buchstaben c an die Position pos im String s, sofern es sich bei pos um eine vernuenftige Positionsangabe handelt.

char str_getchar(mystring *s, int pos);
//Liefert den Buchstaben an der Position pos im String s oder 0, wenn die Position im String nicht existiert. 

