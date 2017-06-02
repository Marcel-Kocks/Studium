#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
/* Signal Handler */
void sighand()
{
    printf("Signal ist eingetroffen\n");
}
/* Hauptprogramm */
main()
{
    int Kind_pid;
    /* Bindung des Signal Handlers sighand() an das Signal SIGUSR1 */
    struct sigaction sigact;
    sigact.sa_handler = sighand;
    sigemptyset(&sigact.sa_mask);
    sigact.sa_flags = 0;
    sigaction(SIGKILL,&sigact,0);
    if ((Kind_pid=fork())==0)
    {
        printf("Kind wartet auf Signal\n");
        pause();
        printf("Kind terminiert\n");
        exit(0);
    }
    printf("Eltern tut zunächst etwas anderes\n");
    sleep(2);
    printf("Eltern schickt Signal an Kind\n\n");
    kill(Kind_pid, SIGKILL);
}
