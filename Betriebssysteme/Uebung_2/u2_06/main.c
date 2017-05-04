#include <signal.h>
#include <stdio.h>
main() {
    int sohn_pid, i=0;
    if ((sohn_pid=fork())==0) {
        /* Endlosschleife des Sohns */
        while (1) printf("Sohn: %d\n",i++);
    }
    sleep(2);
    /* Der Vater beendet den Sohn */
    printf("Vater: tötet Sohn\n");
    kill(sohn_pid,SIGKILL);
}
