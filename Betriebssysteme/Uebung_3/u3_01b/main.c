#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <pthread.h>
#define NUMBER_OF_THREADS 10
#define TRUE 1
int a = 0;
int b = 0;
pthread_mutex_t lock1;

void *print_hello_world(void *tid)
{
    printf("Hello World. Greetings from thread %d \n", tid);
    long i;
    sleep(5);
    for( i = 0; i < 100000; i++ ) {
        pthread_mutex_lock(&lock1);
        a = (int) tid;
        b = (int) tid;
        if ( a != b) {
            printf("Fehler: a = %d und b = %d in Thread %d \n", a, b,tid);
        }
        pthread_mutex_unlock(&lock1);
    }
    printf("%d. Thread fertig \n", tid);
    pthread_exit(0);
}
int main(int argc, char *argv[])
{
    pthread_t threads[NUMBER_OF_THREADS];
    pthread_mutex_init(&lock1,NULL);
    int status, i;
    for(i =0; i < NUMBER_OF_THREADS; i++) {
        printf("Main here. Creating thread %d \n", i);
        status = pthread_create(&threads[i], NULL, print_hello_world,
                                (void *)i );
        if (status != 0) {
            printf("Oops. pthread_create returned error code %d \n",
                   status);
            exit(-1);
        }
    }
    //while(TRUE);
    int it;
    for(it=0;it<10;it++){
        pthread_join(threads[it],NULL);
    }
    pthread_mutex_destroy(&lock1);
    exit(0);
}
