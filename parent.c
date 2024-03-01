// Importacion de Librerias
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Desarrollo del programa - Función Main
int main()
{

    int i, pid, pid1, pid2;

    // Duplicacion del proceso padre
    pid = fork();

    printf("--- PID Principal: %d --- \n\n", pid);

    if (pid == 0)
    {
        char *args[] = {"10", "20", "30", NULL};
        execv("./acumulado", args);
    }
    else
    {
        // Duplicacion del proceso
        pid1 = fork();

        printf("--- PID Secundario: %d --- \n\n", pid1);

        if(pid1 == 0)
        {
            for (i = 0; i < 10; i++)
            {
                printf(
                    "--- Hijo[2] --> PID: %d ---\n --- PPID: %d ---\n i = %d --- \n\n", getpid(), getppid(), i
                );
            }
            
        }
        else
        {
            wait(NULL);
            wait(NULL);

            printf("--- Padre --> PID: %d\n\n", getpid());
        }

    }

    return 0;
}