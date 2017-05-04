#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char **argv)
{
    int fd;
    char d[10];
    size_t k = sizeof(d); /* Sinnlos, aber macht Compiler glücklich */
    fd = open("klaus", O_WRONLY|O_CREAT);
    printf("Eltern schreibt in klaus: Esel Hund Maus Igel Rabe Wurm\n");
    write( fd, "Esel", 4);
    write( fd, "Hund", 4);
    write( fd, "Maus", 4);
    write( fd, "Igel", 4);
    write( fd, "Rabe", 4);
    write( fd, "Wurm", 4);
    close(fd);
    fd = open("klaus", O_RDONLY);
    if(fork() == 0)
    {
        /* Kind */
        read(fd, d, 4);
        printf("Kind: %s \n", d);
        read(fd, d, 4);
        printf("Kind: %s \n", d);
        read(fd, d, 4);
        printf("Kind: %s\n", d);
        sleep(5);
        exit(0);
    }
    else
    {
        /* Eltern */
        read(fd, d, 4);
        printf("Eltern: %s \n", d);
        read(fd, d, 4);
        printf("Eltern: %s \n", d);
        read(fd, d, 4);
        printf("Eltern: %s\n", d);
        sleep(2);
        close(fd);
        return 0;
    }
}
