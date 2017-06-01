#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define NUMBER_OF_THREADS 10
#define TRUE 1
int a = 0;
int b = 0;
void *print_hello_world(void *tid)
{
    printf("Hello World. Greetings from thread %d \n", tid);
    long i;
    sleep(5);
    for( i = 0; i < 100000; i++ ) {
        a = (int) tid;
        b = (int) tid;
        if ( a != b) {
            printf("Fehler: a = %d und b = %d in Thread %d \n", a, b,tid);
        }
    }
    printf("%d. Thread fertig \n", tid);
    pthread_exit(0);
}
int main(int argc, char *argv[])
{
    pthread_t threads[NUMBER_OF_THREADS];
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
    while(TRUE);
    exit(0);
}
