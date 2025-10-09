/*************************************************************************************************************
*            Pontificia Universidad Javeriana                                                                *
*                                                                                                            *
* Autor:     Thomas Leal Puerta                                                                              *
* Fecha:     7 de Octubre, 2025                                                                              *
* Materia:   Sistemas Operativos                                                                             *
* Profesor:  John Jairo Corredor                                                                             *
* Objetivo:  Demostrar el uso de la funcion fork() para la creacion de procesos hijo y padre.                *
*                                                                                                            *
**************************************************************************************************************
*                                                                                                            *
* HOW TO USE                                                                                                 *
*                                                                                                            *
* HOW TO COMPILE TO PRODUCE EXECUTABLE PROGRAM:                                                              *
*   Linux/macOS:          gcc lab2_tleal.c -o lab2                                                           *
*   Windows (MinGW):      gcc lab2_tleal.c -o lab2.exe                                                       *
*                                                                                                            *
* HOW TO RUN THE PROGRAM:                                                                                    *
*   Linux/macOS:          ./lab2                                                                             *
*   Windows (CMD):        lab2.exe                                                                           *
*   Windows (PowerShell): .\lab2.exe                                                                         *
*************************************************************************************************************/

/************************************************* Headers **************************************************/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/************************************************************************************************************/
/*                                                                                                          */
/*  int main();                                                                                             */
/*                                                                                                          */
/*  Proposito: Demostrar la bifurcacion de procesos mediante la llamada al sistema fork(),                  */
/*             diferenciando la ejecucion del proceso padre y del proceso hijo.                             */
/*                                                                                                          */
/*  Retorno:   0 si el programa finaliza correctamente.                                                     */
/*                                                                                                          */
/************************************************************************************************************/
int main() {

    /* ---- Se crea el fork y se guarda el PID devuelto ---- */
    int procesoID = fork();

    /* ---- Se verifica si es el proceso padre ---- */
    if (procesoID > 0) {
        printf("\t ##==> Proceso Padre con ID %d\n", getpid());
    } else {
        /* ---- En caso contrario, es el proceso hijo ---- */
        printf("\t ##==> Proceso Hijo con ID %d\n", getpid());
    }

    /* ---- Mensaje común para ambos procesos ---- */
    printf("A partir de aqui continúa la ejecucion del proceso main o proceso principal.\n");

    return 0;
}