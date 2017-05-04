#include<stdio.h>
#include<stdlib.h>

int main() {

int sohn_pid;
    if ((sohn_pid=fork())==0) {
        printf("\nSohn: Eigene PID ist %d\n",getpid());
        printf("Sohn: Vater-PID ist %d\n",getppid());
        sleep(4);
        printf("Sohn: und tschüß\n");
        exit(0);
    }
    sleep(1); /* Vaterausgabe soll nach der Sohnausgabe kommen */
    printf("\nVater: Eigene PID ist %d\n",getpid());
    printf("Vater: Sohn-PID ist %d\n",sohn_pid);
    sleep(6);
    printf("Vater: und tschüß\n");
    return 0;
}
