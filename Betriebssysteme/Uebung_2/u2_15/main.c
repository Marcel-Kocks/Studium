#include <stdio.h>

int main(int argc, char **argv) {
    
    int pid = fork();
    if(pid == 0){
        printf("Vater\n");        
    }else{
        printf("Kind\n");
        pid = fork();
    if(pid == 0){
        printf("Kind\n");        
    }else{
        printf("Enkelkind\n");
        pid = fork();
    if(pid == 0){
        printf("Enkelkind\n");        
    }else{
        printf("Urenkelkind\n");
        
    }
        
    }
    }
    
    
    return 0;
}
