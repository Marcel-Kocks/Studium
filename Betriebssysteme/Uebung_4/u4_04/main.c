/* Interprozesskommunikation mit einer unbenannten Pipe */
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
int main()
{
    int fd[2]; /* fd[0] für Lesen und fd[1] für Schreiben */
    int L;
    char buffer[80];
    pipe(fd);
    if (fork() == 0)
    {
        close(fd[1]); /* Kind-Prozess möchte nicht schreiben*/
        printf("Kind wartet vor lesen \n");
        L = read(fd[0], buffer, 79);
        printf("Kind hinter lesen \n");
        buffer[L] = '\0';
        printf("Received string: '%s'\n", buffer);
        close(fd[0]);
        return(0);
    }
    close(fd[0]); /* Eltern-Prozess möchte nicht lesen */
    sleep(1);
    printf("Eltern vor schreiben \n");
    write(fd[1], "Test!", 5);
    printf("Eltern hinter schreiben \n");
    wait(NULL);
    close(fd[1]);
    return(0);
}
