#include <stdio.h>
int main()
{
    char *argv[3] = {"cpmmand line", "_", NULL};
    int pid = fork();
    if (pid == 0)
        execvp("find", argv);
    wait(2);
    printf("Finished executing the parent process - the child process won't get here you will only see this once.\n");
    return 0;
}