#include <stdio.h>
#include <pthread.h>

struct eqaul{
    float op1;
    float op2;
    char op;
    float erg;
};

void* calc(void * eq){
    struct eqaul* eqq = (struct eqaul*) eq;
    switch(eqq->op){
        case '+' : eqq->erg=eqq->op1 + eqq->op2;break;
        case '-' : eqq->erg=eqq->op1 - eqq->op2;break;
        case '*' : eqq->erg=eqq->op1 * eqq->op2;break;
        case '/' : eqq->erg=eqq->op1 / eqq->op2;break;
    }
    return &(eqq->erg);    
}

int main(int argc, char **argv) {
    
    struct eqaul arr_eq[4];
    arr_eq[0] = (struct eqaul){12,24,'+'};
    arr_eq[1] = (struct eqaul){13,24,'+'};
    arr_eq[2] = (struct eqaul){14,24,'+'};
    arr_eq[3] = (struct eqaul){15,24,'+'};
    
    pthread_t threads[4];
    
    int i;
    for(i=0;i<4;i++){
        pthread_create(&threads[i],NULL,calc,arr_eq+i);
    }
    
    for(i=0;i<4;i++){
        float* erg;
        pthread_join(threads[i],(void**)&erg);
        printf("OUT: %f\n",*erg);
    }
      
    
    printf("Fertig!\n");
    //sleep(5);
    return 0;
}
