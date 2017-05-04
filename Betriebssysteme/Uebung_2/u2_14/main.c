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
    if(fork() == 0)
    {
        /* Kind */
        printf("Kind schreibt in klaus: Esel Hund Maus\n");
        write( fd, "Esel", 4);
        write( fd, "Hund", 4);
        write( fd, "Maus", 4);
        sleep(5);
        exit(0);
    }
    else
    {
        /* Eltern */
        sleep(1);
        printf("Eltern schreibt in klaus: Igel Rabe Wurm\n");
        write( fd, "Igel", 4);
        write( fd, "Rabe", 4);
        write( fd, "Wurm", 4);
        sleep(2);
        close(fd);
        fd = open("klaus", O_RDONLY);
        read(fd, d, 4);
        printf("%s \n", d);
        read(fd, d, 4);
        printf("%s \n", d);
        read(fd, d, 4);
        printf("%s\n", d);
        read(fd, d, 4);
        printf("%s \n", d);
        read(fd, d, 4);
        printf("%s \n", d);
        read(fd, d, 4);
        printf("%s\n", d);
        close(fd);
        return 0;
    }
}
