/* Pipes als Standardein- und -ausgabe */
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
int main()
{
    int fd1[2], fd2[2], l;
    char buffer[80];
    pipe(fd1);
    pipe(fd2);

    if (fork() == 0)
    {
        close(fd1[1]); /* Kind-Prozess */
        close(fd2[0]);
        dup2(fd1[0], STDIN_FILENO );
        dup2(fd2[1], STDOUT_FILENO);

        close(fd1[0]);
        close(fd2[1]);
        execlp("sort", "sort", NULL); /* Es wird der "Sortier-Prozess" geladen */
        perror("pipe2: execlp() failed");
        return(1);
    }
    close(fd1[0]); /* Eltern-Prozess */
    close(fd2[1]);
    write(fd1[1], "These\nlines\nshall\nbe\nsorted\n", 28);
    close(fd1[1]);
    wait(NULL);
    l = read(fd2[0], buffer, 79);
    write(STDOUT_FILENO, buffer, l);
    close(fd2[0]);
    return(0);
}
