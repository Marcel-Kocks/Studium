#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char **argv)
{
    FILE *pf;
    char d[10];
    pf = fopen("fritz", "w+");
    fputs("Esel", pf);
    fputs("Hund", pf);
    fputs("Maus", pf);
    fputs("Igel", pf);
    fputs("Rabe", pf);
    fputs("Wurm", pf);
    fclose(pf);
    pf = fopen("fritz", "r");
    if(fork() == 0)
    {
        /* Kind */
        fgets(d, 5, pf);
        printf("Kind: %s \n", d);
        fgets(d, 5, pf);
        printf("Kind: %s \n", d);
        fgets(d, 5, pf);
        printf("Kind: %s\n", d);
        sleep(5);
        exit(0);
    }
    else
    {
        /* Eltern */
        fgets(d, 5, pf);
        printf("Eltern: %s \n", d);
        fgets(d, 5, pf);
        printf("Eltern: %s \n", d);
        fgets(d, 5, pf);
        printf("Eltern: %s\n", d);
        sleep(2);
        fclose(pf);
        return 0;
    }
}
