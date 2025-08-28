
/*************************************************************************************************************
*            Pontificia Universidad Javeriana                                                                *
*                                                                                                            *
* Autor:     Thomas Leal Puerta                                                                              *
* Fecha:     27 de Agosto, 2025                                                                              *
* Materia:   Sistemas Operativos                                                                             *
* Profesor:  John Jairo Corredor                                                                             *
* Objetivo:  Implementacion de Challenge5                                                                    *
*                                                                                                            *
**************************************************************************************************************
*                                                                                                            *
**************************************************************************************************************
*                                                                                                            *
* HOW TO USE                                                                                                 *
*                                                                                                            *
* HOW TO COMPILE TO PRODUCE EXECUTABLE PROGRAM:                                                              *
*   Linux/macOS:          gcc challenge5.c -o reto5                                                          *
*   Windows (MinGW):      gcc challenge5.c -o reto5.exe                                                      *
*                                                                                                            *
* HOW TO RUN THE PROGRAM:                                                                                    *
*   Linux/macOS:          ./reto5                                                                            *
*   Windows (CMD):        reto5.exe                                                                          *
*   Windows (PowerShell): .\reto5.exe                                                                        *
*************************************************************************************************************/

/************************************************* Headers **************************************************/
#include <stdio.h>
#include <stdlib.h>

/************************************************************************************************************/
/*                                                                                                          */
/*  int main();                                                                                             */
/*                                                                                                          */
/*  Propósito: Demostrar asignación dinámica, copia e impresión de cadenas                                  */
/*             en C usando realloc, scanf, printf y free.                                                   */
/*                                                                                                          */
/*  Retorno:   0 si finaliza correctamente.                                                                 */
/*                                                                                                          */
/************************************************************************************************************/
int main(){
    /* ---- Se declara un apuntador a int --------------------------------------------------------------- */
    int *ptr;
    /* ---- Se declara dos enteros para almacenar el tamaño de la memoria a asignar y el nuevo tamaño --- */
    int n1, n2;

    printf("Enter size: ");
    /* ---- Se lee el tamaño de la memoria a asignar ---------------------------------------------------- */
    scanf("%d", &n1);
    
    /* ---- Se reserva memoria para n1 enteros ---------------------------------------------------------- */
    ptr = malloc(n1 * sizeof *ptr);

    printf("Addresses of previously allocated memory: ");
    /* ---- Se imprime la dirección de memoria de cada elemento del arreglo ----------------------------- */
    for (int i = 0; i < n1; ++i) {
        printf("\n\np = %p\n", ptr + i);
    }

    printf("Enter the new size: ");
    /* ---- Se lee el nuevo tamaño de la memoria a asignar ----------------------------------------------- */
    scanf("%d", &n2);

    /* ---- Se reasigna memoria para n2 enteros ---------------------------------------------------------- */
    ptr = realloc(ptr, n2 * sizeof *ptr);

    printf("Addresses after realloc:\n");
    /* ---- Se imprime la dirección de memoria de cada elemento del arreglo ----------------------------- */
    for (int i = 0; i < n2; ++i) {
        printf("\n\np = %p\n", ptr + i);
    }

    /* ---- Se libera la memoria reservada para el arreglo ---------------------------------------------- */
    free(ptr);
    return 0;
}
