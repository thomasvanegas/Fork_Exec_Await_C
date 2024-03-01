// Importacion de paquetes
#include <stdio.h>

// Función main - Desarrollo del programa
int main (int argc, char *argv[])
{

    int acumulado = 0;

    printf("--- Estamos dentro del acumulado.c ---\n\n");
    printf("--- PID de acumulado.c: %d --- PPID: %d\n\n", getpid(), getppid());

    for (int i = 0; i < argc; i++)
    {
        acumulado += atoi(argv[i]);
    }

    printf("--- Valor Acumulado: %d --- \n\n", acumulado);

    return 0;
    

}