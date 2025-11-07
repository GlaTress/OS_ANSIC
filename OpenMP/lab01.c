/*************************************************************************************************************
*            Pontificia Universidad Javeriana                                                                *
*                                                                                                            *
* Autor:     Thomas Leal Puerta                                                                              *
* Fecha:     4 de Noviembre de 2025                                                                          *
* Materia:   Sistemas Operativos                                                                             *
* Profesor:  John Jairo Corredor, PhD                                                                        *
* Tema:      Introducción a OpenMP: directivas, compilación y ejecución con múltiples hilos.                 *
*                                                                                                            *
* Objetivo:  Introduccion en laboratorio openp clausulas y directivas para el programa                       *
*                                                                                                            *
**************************************************************************************************************
*                                                                                                            *
* HOW TO USE                                                                                                 *
* ---------------------------------------------------------------------------------------------------------- *
* Compilar :  gcc -fopenmp lab01.c -o lab01                                                                  *
* Ejecutar :  ./lab01                                                                                        *
*                                                                                                            *
* Descripción del programa:                                                                                  *
*  - Imprime el número máximo de hilos disponibles para OpenMP.                                              *
*  - Crea una región paralela donde cada hilo imprime su identificador.                                      *
*                                                                                                            *
*************************************************************************************************************/

/************************************************* Headers **************************************************/
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

/************************************************************************************************************/
/*                                                                                                          */
/*  int main(int argc, char *argv[]);                                                                       */
/*                                                                                                          */
/*  Propósito: Ejecutar un ejemplo introductorio a OpenMP, mostrando el uso de regiones paralelas           */
/*             y la obtención del número de hilos activos e identificadores de cada uno.                    */
/*                                                                                                          */
/*  Retorno:   0 si finaliza correctamente.                                                                 */
/*                                                                                                          */
/************************************************************************************************************/
int main(int argc, char *argv[]) {

    /* ---- Mostrar el número máximo de hilos que el sistema puede usar con OpenMP ---- */
    printf("OpenMP ejecutando con %d hilos \n", omp_get_max_threads());

    /* ---- Región paralela: cada hilo ejecuta el bloque de código dentro de la directiva ---- */
    #pragma omp parallel
    {
        /* ---- Imprimir el identificador del hilo actual ---- */
        printf("Hello world desde el thread %d\n", omp_get_thread_num());
    }

    /* ---- Finalización del programa principal ---- */
    return 0;
}
