#include <sys/sem.h>
#include <stdlib.h>
#include <stdio.h>
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include "main.h"

#define N 5                 /* Anzahl der Philosophen */
#define LEFT (i+N-1)%N      /* Anzahl von i's linkem Nachbarn */
#define RIGHT (i+1)%N       /* Anzahl von i's rechtem Nachbarn */
#define THINKING 0          /* Philosoph denkt */
#define HUNGRY 1            /* Philosoph versucht Gabeln zu bekommen */
#define EATING 2            /* Philosoph isst */
#define TRUE 1
int state[N];               /* Feld mit dem Status jedes Philosophen */
pthread_mutex_t mutex;      /* wechselseitiger Ausschl. für krit. Reg. */
pthread_mutex_t s[N];       /* ein Semaphor pro Philosoph */


int main(int argc, char *argv[])
{
    pthread_t threads[N];
    int status, i;
    pthread_mutex_init(&mutex,NULL);
    for(i=0;i<N;i++){
        pthread_mutex_init(&s[i],NULL);       
    }
    for(i =0; i < N; i++) {
        printf("Main here. Creating thread %d \n", i);
        int* input = malloc(sizeof(int));
        *input=i;
        status = pthread_create(&threads[i], NULL, philosopher,(void *) input );
        if (status != 0) {
            printf("Oops. pthread_create returned error code %d \n",
                   status);
            exit(-1);
        }
    }

    for(i=0;i<N;i++){
        pthread_join(threads[i],NULL);        
    }
    
    for(i=0;i<N;i++){
        pthread_mutex_destroy(&s[i]);       
    }
    
    pthread_mutex_destroy(&mutex);
    
    exit(0);
}

void* philosopher (void* in)    /* i: Nummer des Philosophen (von 0 bis N-1)*/
{
    int i = *((int *) in);
    //int i=(int) in;
    int a;
    for(a=0;a<100;a++)
    {                       /* Endlosschleife */
        think(i);            /* Philosoph denkt */
        take_forks(i);      /* nimm zwei Gabeln oder blockiere */
        eat(i);              /* mjam, mjam, Spaghetti */
        put_forks(i);       /* lege beide Gabeln zurück auf den Tisch */
    }
    return NULL;
}

void take_forks (int i)     /* i: Nummer des Philosophen (von 0 bis N-1)*/
{
    pthread_mutex_lock(&mutex);           /* Eintritt in kritische Region */
    state[i] = HUNGRY;      /* registriere, dass Philosoph i hungrig ist*/
    test(i);                /* versuche zwei Gabeln zu bekommen */
    pthread_mutex_unlock(&mutex);             /* verlasse kritische Region */
    pthread_mutex_lock(&s[i]);            /* blockiere, wenn Gabeln nicht erhalten */
}


void put_forks ( int i)     /* i: Nummer des Philosophen (von 0 bis N-1)*/
{
    pthread_mutex_lock(&mutex); /* Eintritt in kritische Region */
    state[i] = THINKING; /* Philosoph hat Essen beendet*/
    test(LEFT); /* kann der linke Nachbar jetzt essen? */
    test(RIGHT); /* kann der rechte Nachbar jetzt essen? */
    pthread_mutex_unlock(&mutex); /* verlasse kritische Region */
}
void test (int i) /* i: Nummer des Philosophen (von 0 bis N-1) */
{
    if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] !=EATING) {
        state[i] = EATING;
        pthread_mutex_unlock(&s[i]);
    }
}

void eat(int i){
    int j; j = rand() /10000000; printf("Philosoph %d isst\n", i); 
    usleep(j);
}

void think(int i){
    int j; j = rand() /10000000; printf("Philosoph %d denkt\n", i); 
    usleep(j);
}
