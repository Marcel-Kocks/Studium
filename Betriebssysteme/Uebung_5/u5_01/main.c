#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
pthread_mutex_t mutex_A, mutex_B;
int control = 5;
int ende = 1;
void Thread_A(void)
{
    while(1) {
        pthread_mutex_lock(&mutex_A);
        pthread_mutex_lock(&mutex_B);
        usleep(1);

        control = 0;

        pthread_mutex_unlock(&mutex_B);
        pthread_mutex_unlock(&mutex_A);

    }
}

void Thread_B(void)
{
    while(1) {
        pthread_mutex_lock(&mutex_A);
        usleep(1);
        pthread_mutex_lock(&mutex_B);

        control = 0;

        pthread_mutex_unlock(&mutex_B);
        pthread_mutex_unlock(&mutex_A);
    }
}

// Dieser Thread prüft, ob ein Deadlock vorliegt!
void Thread_C(void)
{
    sleep(2);
    if(control == 5 ) {
        printf("DEADLOCK!!! \n");
    }
    else {
        printf("ALLES NETT \n");
    }
    ende = 0;
}

int main(int argc, char *argv[])
{
    pthread_t threads[3];

    pthread_mutex_init(&mutex_A, NULL);
    pthread_mutex_init(&mutex_B, NULL);

    printf("Main here. Creating thread A \n");
    pthread_create(&threads[0], NULL, Thread_A, 0);

    printf("Main here. Creating thread B \n");
    pthread_create(&threads[1], NULL, Thread_B, 0);

    printf("Main here. Creating thread C \n");
    pthread_create(&threads[2], NULL, Thread_C, 0);

    while(ende);
    exit(0);
}
