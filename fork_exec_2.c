#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main(){

    int pid = fork();

    printf("Proceso Padre: %d \n", pid);

    if (pid == 1) {
        return 1;
    }

    printf("Process ID: %d \n", getpid());

    if (pid != 0){
        wait(NULL);
    }

}