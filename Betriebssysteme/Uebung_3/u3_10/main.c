#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <semaphore.h>


#define NUM_MAX 15
#define NUM_CHAIRS 5
#define MAX_CUSTOMERS 50

#define TRUE 1
// Function prototypes...
void *customer(void *num);
void *barber(void *);
void *createRandomCustomer(void *);


// Define the semaphores.

// waitingRoom Limits the # of customers allowed
// to enter the waiting room at one time.
sem_t waitingRoom;

// barberChair ensures mutually exclusive access to
// the barber chair.
sem_t barberChair;

// barberPillow is used to allow the barber to sleep
// until a customer arrives.
sem_t barberPillow;

// seatBelt is used to make the customer to wait until
// the barber is done cutting his/her hair.
sem_t seatBelt;

int alldone=0;

int main(int argc, char *argv[]) {
    pthread_t btid,rtid;
    int i;
    
    // Initialize the semaphores with initial values...
    sem_init(&waitingRoom, 0, NUM_CHAIRS);
    sem_init(&barberChair, 0, 1);
    sem_init(&barberPillow, 0, 0);
    sem_init(&seatBelt, 0, 0);

    // Create the barber.
    pthread_create(&btid, NULL, barber, NULL);
    
    // Create the "random" Creator
    pthread_create(&rtid, NULL, createRandomCustomer, NULL);
    
    
    pthread_join(rtid,NULL);
    
    alldone=1;
    // Wake up Barber so he can terminate.
    sem_post(&barberPillow);
    
    kill(btid,SIGKILL);

    pthread_join(btid,NULL);
}

void *customer(void *number) {
    int num = *(int *)number;

    // Leave for the shop and take some random amount of
    // time to arrive.
    printf("Customer %d arrived at barber shop.\n", num);

    // Wait for space to open up in the waiting room...
    int freeSeats;
    sem_getvalue(&waitingRoom,&freeSeats);
    if(freeSeats==0){
        printf("Customer %d: Waiting room full,leaving.\n", num);
        return NULL;
    }
    sem_wait(&waitingRoom);
    printf("Customer %d: Entering waiting room.\n", num);

    // Wait for the barber chair to become free.
    sem_wait(&barberChair);

    // The chair is free so give up your spot in the
    // waiting room.
    sem_post(&waitingRoom);

    // Wake up the barber...
    printf("Customer %d waking the barber.\n", num);
    sem_post(&barberPillow);

    // Wait for the barber to finish cutting your hair.
    sem_wait(&seatBelt);

    // Give up the chair.
    sem_post(&barberChair);
    printf("Customer %d leaving barber shop.\n", num);
    
    return NULL;
}

void *barber(void *junk) {
    // While there are still customers to be serviced...
    // Our barber is omnicient and can tell if there are
    // customers still on the way to his shop.
    while (TRUE) {

        // Sleep until someone arrives and wakes you..
        printf("The barber is sleeping\n");
        sem_wait(&barberPillow);
        
        if(alldone){
            printf("The barber has finisched, going home now.\n");
            return NULL;
        }
        
        // Take a random amount of time to cut the
        // customer's hair.
        printf("The barber is cutting hair\n");
        sleep(2);
        printf("The barber has finished cutting hair.\n");

        // Release the customer when done cutting...
        sem_post(&seatBelt);
    }
}

void *createRandomCustomer(void *junk){
    pthread_t cThreads[MAX_CUSTOMERS];
    int Numbers[MAX_CUSTOMERS];
    int i;
    for(i=0;i<MAX_CUSTOMERS;i++){
        Numbers[i]=i;
        //wait 1 to 3 sec
        usleep(rand()%3000000);
        pthread_create(&cThreads[i],NULL,customer,(void*) &Numbers[i]);
    }
    
    for(i=0;i<MAX_CUSTOMERS;i++){
        pthread_join(cThreads[i],NULL);
    }
    return NULL;
}

