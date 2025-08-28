/*************************************************************************************************************
*            Pontificia Universidad Javeriana                                                                *
*                                                                                                            *
* Autor:     Thomas Leal Puerta                                                                              *
* Fecha:     27 de Agosto, 2025                                                                              *
* Materia:   Sistemas Operativos                                                                             *
* Profesor:  John Jairo Corredor                                                                             *
* Objetivo:  Implementacion de Challenge2                                                                    *
*                                                                                                            *
**************************************************************************************************************
*                                                                                                            *
**************************************************************************************************************
*                                                                                                            *
* HOW TO USE                                                                                                 *
*                                                                                                            *
* HOW TO COMPILE TO PRODUCE EXECUTABLE PROGRAM:                                                              *
*   Linux/macOS:          gcc challenge2.c -o reto2                                                          *
*   Windows (MinGW):      gcc challenge2.c -o reto2.exe                                                      *
*                                                                                                            *
* HOW TO RUN THE PROGRAM:                                                                                    *
*   Linux/macOS:          ./reto2                                                                            *
*   Windows (CMD):        reto2.exe                                                                          *
*   Windows (PowerShell): .\reto2.exe                                                                        *
*************************************************************************************************************/

/************************************************* Headers **************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/************************************************************************************************************/
/*                                                                                                          */
/*  int main();                                                                                             */
/*                                                                                                          */
/*  Propósito: Demostrar asignación dinámica, copia e impresión de cadenas                                  */
/*             en C usando malloc, strcpy, printf y free.                                                   */
/*                                                                                                          */
/*  Retorno:   0 si finaliza correctamente.                                                                 */
/*                                                                                                          */
/************************************************************************************************************/
int main() {
    /* ---- Se declara un apuntador a char inicializado en NULL ------------------------------------------ */
    char *q = NULL;

    printf("Requesting space for \"Goodbye\"\n");

    /* ---- Reserva strlen + 1 para el terminador '\0' --------------------------------------------------- */
    q = malloc(strlen("Goodbye") + 1);

    /* ---- Verifica si la asignación fue exitosa -------------------------------------------------------- */  
    if (!q) {
    /* ---- Si no se pudo asignar memoria, se muestra un mensaje de error y se termina el programa ------- */
        perror("failed to allocate space");
        exit(EXIT_FAILURE);
    }

    /* ---- Muestra la dirección de q correctamente con %p ---------------------------------------------- */
    printf("About to copy \"Goodbye\" to q at address %p\n", q);

    /* ---- Copia y muestra ----------------------------------------------------------------------------- */
    strcpy(q, "Goodbye");
    printf("String copied\n");

    /* ---- Imprime la cadena de caracteres de q -------------------------------------------------------- */
    printf("%s\n", q);

    /* ---- Libera memoria ------------------------------------------------------------------------------ */
    free(q);

    return 0;
}
