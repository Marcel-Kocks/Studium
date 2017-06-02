#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/wait.h>
int main()
{
    int shmem_id;
    char *buffer;
    shmem_id = shmget(IPC_PRIVATE, 80, SHM_R | SHM_W); /* Erstellen */
    buffer = shmat(shmem_id, 0, 0); /* Anbinden */
    buffer[0] = '\0'; /* Puffer initialisieren */
    if (fork() == 0)
    {   /* Kind-Prozess */
        sprintf(buffer, "Message from child process");
        shmdt(buffer); /* Anbindung lösen */
        return(0);
    }
    wait(NULL); /* Eltern-Prozess */
    printf("Child process wrote into buffer: '%s'\n", buffer);
    shmdt(buffer); /* Anbindung lösen */
    shmctl(shmem_id, IPC_RMID, 0); /*Löschen */
    return(0);
}
