#pragma once

struct komplex
{
	double real;
	double img;
};

komplex komp_init(double r = 0, double i = 0); // Initialisierung einer komplexen Zahl mit Defaultparametern
int komp_equal(komplex a, komplex b); // Vergleich zweier komplexer Zahlen auf Gleichheit
double komp_abs(komplex k); // Betrag einer komplexen Zahl
komplex komp_add_kk(komplex& a, komplex& b); // Addition von zwei komplexen Zahlen
komplex komp_add_kr(komplex a, double b); // Addition einer komplexen und einer reellen Zahl
komplex komp_mult_kk(komplex& a, komplex& b); // Multiplikation von zwei komplexen Zahlen
komplex komp_mult_kr(komplex a, double b); // Multiplikation einer komplexen und einer reellen Zahl
komplex komp_div_kk(komplex a, komplex b);  // Division von zwei komplexen Zahlen
komplex komp_div_kr(komplex a, double b);  // Division einer komplexen und einer reellen Zahl