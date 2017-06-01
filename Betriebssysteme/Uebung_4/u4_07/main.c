/* Datenaustausch mit Hilfe einer FIFO-Datei */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
    char buffer[80];
    int fd;
    mkfifo("my_fifo", 0600);
    if (fork() == 0)
    {   /* Kind-Prozess */
        fd = open("my_fifo", O_WRONLY|O_CREAT);
        write(fd, "Can you hear me?\n", 20);
        unlink("my_fifo");
        return(0);
    }
    /* Eltern-Prozess */
    fd = open("my_fifo", O_RDONLY);
    read(fd, buffer, 20);
    printf("Child process sent: %s", buffer);
    unlink("my_fifo");
    return(0);
}
