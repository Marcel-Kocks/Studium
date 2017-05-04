#include <stdio.h>
#include <stdlib.h>


main() {
    int status;
    if (fork()==0) {
        printf("Sohn: Ich schlafe jetzt\n");
        sleep(2);
        printf("Sohn: Ich bin jetzt fertig\n");
        exit(0);
    }
    printf("Vater: Ich warte auf den Sohn\n");
    wait(&status);
    printf("Vater: Sohn ist jetzt fertig\n");
}
