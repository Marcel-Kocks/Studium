#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUMBER_OF_THREADS 2
void *print_hello_world(void *tid)
{
    printf("Hello World. Greetings from thread %d \n", tid);
    printf("Ich gehe jetzt schlafen\n");
    while(1);
    pthread_exit(0);
}
int main(int argc, char *argv[])
{
    pthread_t threads[NUMBER_OF_THREADS];
    int status, i;
    for(i =0; i < NUMBER_OF_THREADS; i++)
    {
        printf("Main here. Creating thread %d \n", i);
        status = pthread_create(&threads[i], NULL, print_hello_world, (void *)i );
    }
    sleep(60);
    printf("Jetzt clone ich mich\n");
    if (fork()==0)
    {
        printf("Hier ist der Sohn\n");
        i = 2;
        status = pthread_create(&threads[i], NULL, print_hello_world, (void *)i );
    }
    else
    {
        printf("Hier ist der Vater\n");
        i = 3;
        status = pthread_create(&threads[i], NULL, print_hello_world, (void *)i );
    }
    while(1);
    exit(0);
}
