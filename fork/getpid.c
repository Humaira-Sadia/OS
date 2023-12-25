#include <stdio.h>
int main()
{
    printf("The process identifier(pid) of the parent process is %d\n", (int)getpid());
    int p = fork();
    if (p == 0)
        printf("After the fork, the process identifier (pid) of the child is %d\n", (int)getpid());
    else
        printf("After the fork, the process identifier (pid) of the parent is %d \n fork() returned %d\n", (int)getpid(), p);
}