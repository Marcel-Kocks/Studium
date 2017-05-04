#include <stdio.h>
#include <stdlib.h>

int main(){
    if(fork()==0){
        printf("Hier ist der Sohn\n");
        exit(0);
    }
    
    printf("Hier ist der Vater\n");
    return 0;
}
