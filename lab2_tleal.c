/*************************************************************************************************************
*            Pontificia Universidad Javeriana                                                                *
*                                                                                                            *
* Autor:     Thomas Leal Puerta                                                                              *
* Fecha:     7 de Octubre, 2025                                                                              *
* Materia:   Sistemas Operativos                                                                             *
* Profesor:  John Jairo Corredor                                                                             *
* Objetivo:  Demostrar el comportamiento de la funcion fork() en la creacion simultanea                      *
*            de procesos padre e hijo, evidenciando la duplicidad de ejecucion y el "caos de creacion"       *
*            hasta su estabilizacion por el planificador del sistema operativo.                              *
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
**************************************************************************************************************/

/************************************************* Headers **************************************************/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/************************************************************************************************************/
/*                                                                                                          */
/*  int main();                                                                                             */
/*                                                                                                          */
/*  Proposito: Mostrar como, tras la creacion de un proceso con fork(),                                     */
/*             tanto el proceso padre como el hijo ejecutan el mismo codigo de manera concurrente.          */
/*             El orden de impresion varea debido a la planificacion del CPU, generando caos                */
/*             en las impresiones.                                                                          */
/*             En sucesivas ejecuciones, este caos tiende a estabilizarse al asignarse turnos               */
/*             mas predecibles.                                                                             */
/*                                                                                                          */
/*  Retorno:   0 si el programa finaliza correctamente.                                                     */
/*                                                                                                          */
/************************************************************************************************************/
int main() {

    /* ---- Mensaje inicial del proceso principal antes del fork ---- */
    printf("==> Inicio del proceso main o proceso principal <=\n\n\n");

    /* ---- Se realiza la llamada fork(), creando un nuevo proceso hijo ---- */
    int procesoID = fork();

    /* ---- Seccion correspondiente al proceso hijo ---- */
    if (procesoID == 0) {
        printf("\t===> Proceso Hijo recien Creado\n");
    } 
    /* ---- Seccion correspondiente al proceso padre ---- */
    else {
        printf("\t===> Proceso Padre\n");
    }

    /* ---- Ambos procesos ejecutan este bloque en paralelo ---- */
    printf("Imprimiendo.......\n");
    for (int i = 0; i < 5; i++) {
        printf("\t\t == %d == \n", i);
    }

    /* ---- Cierre de impresion compartida ---- */
    printf(".......\n");

    return 0;
}