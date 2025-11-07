/*************************************************************************************************************
*            Pontificia Universidad Javeriana                                                                *
*                                                                                                            *
* Autor:     Thomas Leal Puerta                                                                              *
* Fecha:     4 de Noviembre de 2025                                                                          *
* Materia:   Sistemas Operativos                                                                             *
* Profesor:  John Jairo Corredor, PhD                                                                        *
* Tema:      Introducción a OpenMP: uso de variables privadas y compartidas en regiones paralelas.           *
*                                                                                                            *
* Objetivo:  Analizar el comportamiento de las variables en una región paralela con la cláusula              *
*            private, comparando el ámbito de las variables compartidas y privadas entre hilos.              *
*                                                                                                            *
**************************************************************************************************************
*                                                                                                            *
* HOW TO USE                                                                                                 *
* ---------------------------------------------------------------------------------------------------------- *
* Compilar :  gcc -fopenmp lab03.c -o lab03                                                                  *
* Ejecutar :  ./lab03                                                                                        *
*                                                                                                            *
* Descripción del programa:                                                                                  *
*  - Declara variables compartidas y privadas dentro de un bucle paralelo.                                   *
*  - Utiliza la cláusula private para evitar conflictos de datos entre los hilos.                            *
*  - Demuestra cómo las variables locales de cada hilo no afectan las globales.                              *
*                                                                                                            *
*************************************************************************************************************/

/************************************************* Headers **************************************************/
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

/************************************************************************************************************/
/*                                                                                                          */
/*  int main();                                                                                             */
/*                                                                                                          */
/*  Propósito: Mostrar el uso de la cláusula private en OpenMP y su efecto sobre las variables locales      */
/*             en un bucle paralelo.                                                                        */
/*                                                                                                          */
/************************************************************************************************************/
int main() {

    /* ---- Declaración de variables ---- */
    int i;                 /* variable de iteración del bucle for */
    const int N = 1000;    /* número de iteraciones del bucle */
    int a = 50;            /* variable base compartida */
    int b = 0;             /* variable acumuladora */

    /* ---- Región paralela con bucle for distribuido entre hilos ---- */
    /* ---- Las variables i y a son privadas (cada hilo tiene su propia copia) ---- */
    #pragma omp parallel for private(i) private(a)
    for (i = 0; i < N; i++) {
        /* ---- Cada hilo ejecuta su propia versión de a ---- */
        b = a + i;
    }

    /* ---- Impresión final de resultados ---- */
    printf("a = %d b = %d (Se espera a=50 b=1049)\n", a, b);

    /* ---- Finalización del programa ---- */
    return 0;
}
