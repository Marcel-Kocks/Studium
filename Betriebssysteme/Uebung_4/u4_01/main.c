#include <sys/shm.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
main()
{
    int shmid_1; /* Nummer des Shared-Memory-Segments */
    int shmid_2; /* Nummer des Shared-Memory-Segments */
    int shmid_3; /* Nummer des Shared-Memory-Segments */
    int shmid_4; /* Nummer des Shared-Memory-Segments */
    int shmid_5; /* Nummer des Shared-Memory-Segments */
    char xyz[10];

    /* Erzeugung des Shared-Memory-Segments */
    shmid_1 = shmget(IPC_PRIVATE, 3*sizeof(float) , IPC_CREAT|0551);
    shmid_2 = shmget(IPC_PRIVATE, 4*sizeof(float) , IPC_CREAT|0552);
    shmid_3 = shmget(IPC_PRIVATE, 1*sizeof(int) , IPC_CREAT|0553);
    shmid_4 = shmget(IPC_PRIVATE, 1*sizeof(double), IPC_CREAT|0554);
    shmid_5 = shmget(IPC_PRIVATE, 1*sizeof(xyz) , IPC_CREAT|0555);
    printf("Alles fertig 1: %d 2: %d 3: %d 4: %d 5: %d \n", shmid_1,
           shmid_2, shmid_3, shmid_4, shmid_5);
}
