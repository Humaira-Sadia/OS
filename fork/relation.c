#include <stdio.h>
int main()
{
    int pid = fork();
    if (pid == 0)
        printf("From child with pid = %d, ppid = %d, and fork return value %d\n", getpid(), getppid(), pid);
    else if (pid > 0)
        printf("From parent with pid = %d ppid = %d and fork return value %d\n", getpid(), getppid(), pid);
    else
        printf("Error in fork pid = %d, ppid = %d, and fork return value %d\n", getpid(), getppid(), pid);
}