#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{

    int i;
    pid_t pid;

    pid = fork();

    printf("Proceso Padre: %d \n", pid);

    if (pid < 0)
    {
        printf("La instrucción fork() ha fallado");
    }
    else if (pid == 0) // Esto significa no que el pid es cero, sino, que es el pid child
    {
        for (i = 0; i < 5; i++)
        {
            printf("hijo[1] --> pid = %d y ppid = %d \n El valor de i es: %d \n", getpid(), getppid(), i);
        };
    }
    else
    {

        wait(NULL);

        /*
        wait(NULL); // Permite que la rutina del hijo pare
        printf("PID dentro de la rutina del padre %d \n", pid);
        printf("Rutina del proceso padre con ppid = %d \n\n", getppid());
        */

        for (i = 0; i < 5; i++)
        {
            printf("Rutina del proceso padre, valor de i: %d \n\n", i);
        };
    }

    printf("Process ID: %d \n", getpid());

}