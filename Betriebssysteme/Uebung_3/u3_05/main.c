#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
main()
{
    int semid;
    semid = semget(255, 4, 0333);
    printf("Semophore als nummer %d übernommen \n", semid);
    semctl(semid, 0, IPC_RMID, 0);
    printf("und gelöscht \n");
    exit(0);
}
