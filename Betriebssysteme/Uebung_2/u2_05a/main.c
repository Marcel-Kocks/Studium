/* Programm des Vaters: Erzeugt einen Sohn und laesst ihn dann durch excev() ein
Programm in einer anderen Datei ausfuehren. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
main() {
    int err, status;
    char *parameter[4];
    parameter[0] = malloc(10);
    parameter[1] = malloc(13);
    parameter[2] = malloc(13);
    parameter[3] = 0;
    strcpy(parameter[0],"programm");
    strcpy(parameter[1],"1. Parameter");
    strcpy(parameter[2],"2. Parameter");
    /* oder Direktzuweisung:
    parameter[0] = "programm";
    parameter[1] = "1. Parameter";
    parameter[2] = "2. Parameter";
    parameter[3] = 0; */
    if (fork()==0) {
        /* Aufruf einer Maschinenprogramm-Datei */
        err = execv("u2_05b",parameter);
        printf("Vaterprogram Sohn: Rueckkehr aus execv, Rueckgabe = %d\n",err);
        exit(err); /* Rückkehr nur im Fehlerfall! */
    }
    wait(&status);
    printf("Vater: Sohn beendet, status = %d\n",status);
}
