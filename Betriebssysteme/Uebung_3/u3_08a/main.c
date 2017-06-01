#include <sys/sem.h>
#include <stdlib.h>
#include <stdio.h>
#include <bits/pthreadtypes.h>
#include <pthread.h>


#define TRUE 1

#define NUM_READERS 5
#define NUM_THREADS 7 //NUM_WRITER = NUM_THREADS - NUM_READERS

pthread_mutex_t mutex; /* steuert Zugriff auf ,rc' */
pthread_mutex_t db; /* steuert Zugriff auf die Datenbank */
int rc = 0; /* Anzahl lesende u. lesebereite Prozesse */
int value_a = 5; /* Einträge in die Datenbank */
int value_b = 5; /* Einträge in die Datenbank */

int db_zugriffe;


void read_data_base(int* a,int*  b)
{
    *a = value_a;
    *b = value_b;
    db_zugriffe++;
}
void use_data_read(int a, int b,int i)
{
    if( a != b ) printf("READER %d sagt: a = %d und b = %d sind ungleich\n", i, a, b);
}
void think_up_data(int *a)
{
    *a = rand()/10000000;
}
void write_data_base(int a)
{
    value_a = a;
    usleep(1);
    value_b = a;
}
void* reader (void* z)
{
    int i = *((int *)z);
    int x,y;
    while (TRUE) /* Endlosschleife */
    {
        pthread_mutex_lock(&mutex); /* exklusiver Zugriff auf ,rc' */
        rc = rc + 1; /* ein Leser mehr */
        if (rc == 1) pthread_mutex_lock(&db); /* wenn dies der erste Leser ist ... */
        pthread_mutex_unlock(&mutex); /* exklusiven Zugriff auf ,rc' freigeben*/
        read_data_base(&x, &y); /* Zugriff auf die Daten */
        pthread_mutex_lock(&mutex); /* exklusiver Zugriff auf ,rc' */
        rc = rc - 1; /* ein Leser weniger */
        if (rc == 0) pthread_mutex_unlock(&db); /* wenn dies der letzte Leser war ...*/
        pthread_mutex_unlock(&mutex); /* exklusiven Zugriff auf ,rc' freigeben*/
        use_data_read(x, y, i); /* nicht kritische Region */
    }
}
void* writer (void* z)
{
    int i = *((int *)z);
    int x;

    while (TRUE) /* Endlosschleife */
    {
        think_up_data(&x); /* nicht kritische Region */
        pthread_mutex_lock(&db); /* exklusiver Zugriff */
        write_data_base(x); /* schreibe die neuen Daten */
        pthread_mutex_unlock(&db); /* exklusiven Zugriff freigeben */
    }
}



int main(int argc, char *argv[])
{
    int status, i;
    pthread_mutex_init(&mutex,NULL);
    
    pthread_t Threads[NUM_THREADS];
    
    int * input=(int*) malloc(sizeof(int)*NUM_THREADS);
    
    for(i =0; i < NUM_THREADS; i++) {
        printf("Main here. Creating thread %d \n", i);
        input[i]=i;
        status = pthread_create(&Threads[i], NULL, (i<NUM_READERS)?reader:writer,(void *) (input+i));
        if (status != 0) {
            printf("Oops. pthread_create returned error code %d \n",
                   status);
            exit(-1);
        }
    }
    

    for(i=0;i<NUM_THREADS;i++){
        pthread_join(Threads[i],NULL);        
    }
    
    
    pthread_mutex_destroy(&mutex);
    pthread_mutex_destroy(&db);
    
    exit(0);
}
