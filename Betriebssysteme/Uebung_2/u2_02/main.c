#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int i = 1;
    
    if(fork()==0){
        printf("i im Sohn: %d\n",i);
        i=2;
        printf("i im Sohn: %d\n",i);
        exit(0);
    }
    sleep(2);
    printf("i im Vater: %d\n",i);
    return 0;
}
