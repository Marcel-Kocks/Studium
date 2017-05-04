/* Programm des Sohns:
Wird aus dem Programm in u2_05a aufgerufen.
Dazu muss das Maschinenprogramm, das durch Uebersetzung dieses Programms entsteht,
in der Datei 'u2_05b' stehen
- Uebersetzung also durch 'cc -o u2_05b' */
#include <stdio.h>
#include <stdlib.h>
main(int argc, char *argv[]) {
    int i;
    printf("Sohnprogramm:\n");

    for (i=0; i<argc; i++) /* Ausgabe der erhaltenen Parameter */
        printf(" Parameter %d: %s\n",i,argv[i]);
    exit(0);
}
