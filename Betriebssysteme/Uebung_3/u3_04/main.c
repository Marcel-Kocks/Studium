#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
main()
{
    int semid_1;
    int semid_2;
    semid_1 = semget(IPC_PRIVATE, 3, IPC_CREAT|0777);
    printf("Semophore %d erzeugt \n", semid_1);
    semid_2 = semget(4711, 4, IPC_CREAT|0333);
    printf("Semaphore %d erzeugt \n", semid_2);
    sleep (10);
    printf("Bin wieder aufgewacht und lösche die Semaphoren \n");
    semctl(semid_1, 0, IPC_RMID, 0);
    semctl(semid_2, 0, IPC_RMID, 0);
    exit(0);
}
