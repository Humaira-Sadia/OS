#include <stdio.h>
int main(){
    int pid = fork();
    if(pid == 0){
        printf("I am the child process\n");
    }
   else{
    printf("My child's process id is %d \n", pid);
   } 

   return 0;
}