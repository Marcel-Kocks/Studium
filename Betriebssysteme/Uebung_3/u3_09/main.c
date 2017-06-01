#include <stdio.h>
#include <pthread.h>
#define MAX 10 /* wie viele Nummern sollen erzeugt werden? */
pthread_mutex_t the_mutex;
pthread_cond_t condc, condp; /* Zustandsvariablen für consumer und producer
*/
int buffer = 0; /* Puffer zwischen Erzeuger und Verbraucher*/
void *producer(void *ptr) /* erzeuge Daten */
{
    printf("Hallo - I'm the producer \n"); 
    int i;
    for (i= 1; i <= MAX; i++) {
        pthread_mutex_lock(&the_mutex); /* erlange exklusiven Zugriff aufPuffer */
        printf("p vor while \n"); 
        while (buffer != 0) pthread_cond_wait(&condp, &the_mutex);
        printf("p hinter while \n"); 
        buffer = i; /* lege Element in Puffer */
        pthread_cond_signal(&condc); /* wecke Verbraucher auf */
        pthread_mutex_unlock(&the_mutex); /* gib Zugriff auf Puffer frei */
    }
    pthread_exit(0);
}
void *consumer(void *ptr) /* verbrauche Daten */
{
    printf("Hallo - I'm the consumer \n"); 
    int i;
    for (i = 1; i <= MAX; i++) {
        pthread_mutex_lock(&the_mutex); /* erlange exklusiven Zugriff aufPuffer */
        printf("c vor while \n"); 
        while (buffer == 0 ) pthread_cond_wait(&condc, &the_mutex);
        printf("c hinter while \n"); 
        buffer = 0; /* entnimm Element aus Puffer */
        pthread_cond_signal(&condp); /* wecke Erzeuger auf */
        pthread_mutex_unlock(&the_mutex); /* gib Zugriff auf Puffer frei */
    }
    pthread_exit(0);
}
int main(int argc, char **argv) {
    pthread_t pro, con;
    pthread_mutex_init(&the_mutex, 0);
    pthread_cond_init(&condc, 0);
    pthread_cond_init(&condp, 0);
    pthread_create(&con, 0, consumer, 0);
    pthread_create(&pro, 0, producer, 0);
    pthread_join(pro, 0);
    pthread_join(con, 0);
    pthread_cond_destroy(&condc);
    pthread_cond_destroy(&condp);
    pthread_mutex_destroy(&the_mutex);
}
