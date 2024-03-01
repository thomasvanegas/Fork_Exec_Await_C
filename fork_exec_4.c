// Importacion de librerias

#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

// Código de una sumatoria utilizando el ciclo for

/*

    
    for (i = 0; i <= 5; i++)
    {
        
        // Objetivo -> sumatoria = 0 + 1 + 2 + 3 + 4 + 5 = 15 -> Parent and child deben hacer la sumatoria.
        sumatoria += i;
        printf("El valor de la sumatoria es: %d \n\n", sumatoria);

    }

*/

// Desarrollo del programa - función main

int main()
{

    int i;
    int sumatoria = 0;
    pid_t pid;

    // Almcacenamos el registro de ppid
    pid_t parent_pid = getppid(); // PID del proceso padre principal
    pid_t parent_pid_previous = parent_pid; // PID del proceso padre para el primer hijo

    // Proceso padre crea tres hijos

    for (i = 0; i < 3; i++) {

        // se realizan dos fork() -> 1 * 2 = 2^2 = 4 -> 1 padre y tres hijos
        pid = fork();
        
        // --- Verificar errores que se pueden presentar al invocar a fork() ---

        if (pid < 0) {

            printf("La instrucción fork() ha fallado");
            return 1;

        } else if (pid == 0) {

            // Definicion de variables del proceso hijo
            int j;
            pid_t parent_pid = getppid(); // PID del padre

            printf("Soy el proceso hijo[%d] con PID: %d y mi padre es PPID: %d\n\n", i, getpid(), parent_pid);

            // Ejecucion de la sumatoria
            for (j = 0; j <= 5; j++) {
                sumatoria += j;
            }

            printf("Sumatoria en el proceso hijo[%d] con ID: (%d) y PPID:(%d) -> %d\n\n", i, getpid(), parent_pid,sumatoria);

            return 0; // Importante: terminar el proceso hijo después de completar su tarea

        } else {

            // Identificacion del proceso padre -> número mayor que 0
            printf("Soy el proceso padre con PID: %d\n", getpid());

            // El proceso padre espera a que cada hijo termine antes de continuar
            wait(NULL);   

            if (i == 1)
            {
                // Actualizando el PPID para los siguientes hijos
                parent_pid_previous = parent_pid;
            }
            
        }
    }
    
    return 0;

}