#include <stdio.h>
#include <stdlib.h>

struct comp {
    char* eq;
    struct comp* next;
    struct comp* child;
    double value;
};


void findBrackets(struct comp* in) {
    char* start=in->eq;
    char* end;
    char* tmp;
    short bracketcount=0;
    char* brack0start;
    char* brack0end;


    for(tmp=start; *tmp; tmp++) {
        if(*tmp=='(') {
            if(bracketcount==0)
                brack0start=tmp;
            bracketcount++;
        }
        if(*tmp==')') {
            bracketcount--;

            if(bracketcount==0) {
                brack0end=tmp;
                //create new Child with bracket content
                struct comp * c = malloc(sizeof(struct comp));
                c->eq=malloc(sizeof(char)*(brack0end-brack0start));
                c->child=0;
                c->next=0;
                char * tmp2=c->eq;
                brack0start++;
                for(; brack0start<brack0end; brack0start++,tmp2++) {
                    *tmp2=*brack0start;
                }
                *tmp2=0;

                //attach Child
                printf("Method %s\n",c->eq);
                struct comp* attachTo=in;
                if(attachTo->child==0){
                    attachTo->child=c;
                }else{
                    attachTo=attachTo->child;
                    for(;attachTo->next;attachTo=attachTo->next);
                    attachTo->next=c;
                }
                findBrackets(c);
            }
        }

    }

}


int main(int argc, char **argv) {

    struct comp* eq = malloc(sizeof(struct comp));
    eq->eq="((12) * 4) + (8+5)";
    eq->next=0;
    eq->child=0;

    printf("%s\n",eq->eq);

    findBrackets(eq);
    //Find Brackets


    printf("Fertig!\n");
    return 0;
}
