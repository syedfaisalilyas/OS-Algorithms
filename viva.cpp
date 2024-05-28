#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void fibonacci(int n)
{
    int first = 0, second = 1, next;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a);
        next = first+second;
        first = second;
        second = next;
    }
}

int main(void)
{
    int pipefds[2];
    int limit;

    if (pipe(pipefds) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else
    {
        if (pid == 0)
        {
            // child process
            close(pipefds[1]);
            char readMessage[100];
            read(pipefds[0], readMessage, sizeof(readMessage));
            int n = atoi(readMessage);
            printf("Child Process\n");
            fibonacci(n);
        }
        else if (pid > 0)
        {
            // parent process
            wait();
            close(pipefds[0]);
            printf("Parent Process\n");
            printf("Enter the limit of fibbonaci series: ");
            scanf("%d", &limit);
            char message[100];
            sprintf(message, "%d", limit);
            write(pipefds[1], message, sizeof(message));
        }
        else
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
    }
    return EXIT_SUCCESS;
}