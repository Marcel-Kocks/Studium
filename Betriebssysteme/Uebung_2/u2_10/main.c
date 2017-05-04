/* Terminierung eines Pthreads durch pthread_cancel().*/
#include <pthread.h>
#include <stdio.h>
/* Funktion, die der Thread ausführen soll */
void *endlosschleife() {
    while (1) printf("Hier ist ein Thread\n");
}
/* Hauptprogramm */
int main(int argc, char *argv[]) {
    pthread_t th;
    /* Erzeugung eines Threads */
    pthread_create(&th, NULL, endlosschleife, NULL);
    /* Beenden des Threads nach einer Sekunde */
    sleep(1);
    pthread_cancel(th);
    printf("Thread ist beendet\n");
}
