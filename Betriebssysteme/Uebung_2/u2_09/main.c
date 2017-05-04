/* Warten auf die Terminierung eines Pthreads durch pthread_join().*/
#include <pthread.h>
#include <stdio.h>
/* Funktion, die der Thread ausfuehren soll */
void *schlafe(void *schlafzeit) {
    int sz = *(int*)schlafzeit;
    static int exitcode = 0;
    printf("Thread schlaeft %d Sekunden\n",sz);
    sleep(sz); /* Thread blockiert sich eine Zeit lang */
    printf("Thread ist fertig\n");
    sleep(10);
    pthread_exit(&exitcode); /* Thread beendet sich */
}
/* Hauptprogramm */
int main(int argc, char *argv[]) {
    int schlafzeit = 2; /* Schlafzeit des Threads */
    pthread_t thread_id; /* ID des Threads */
    void *status; /* Rueckkehrstatus des Threads */
    printf("Main erzeugt Thread\n");
    pthread_create(&thread_id, NULL, schlafe, &schlafzeit);
    printf("Main wartet auf Thread in pthread_join()\n");
    pthread_join(thread_id, &status);
    sleep(10);
    printf("Main: Thread beendet mit Status %d\n",*(int*)status);
}
