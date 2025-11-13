/************************************************************************************************
*                               Pontificia Universidad Javeriana                                *
*                                                                                               *
* Autor:     [TU NOMBRE]                                                                        *
* Fecha:     [FECHA]                                                                            *
* Materia:   Sistemas Operativos                                                                *
* Profesor:  [NOMBRE DEL PROFESOR]                                                              *
* Objetivo:  Declarar las estructuras, constantes y prototipos de las funciones relacionadas    *
*            con el sistema productor–spooler usando hilos y variables de condición.            *
*************************************************************************************************
* HOW TO USE                                                                                    *
* ----------------------------------------------------------------------------------------------*
* 1. Incluir este archivo en los módulos que usen el sistema de impresión en búfer:             *
*        #include "producer_spooler.h"                                                          *
* 2. Compilar junto con producer_spooler.c y main.c usando pthreads:                            *
*        gcc -Wall -pthread main.c producer_spooler.c -o spooler_app                            *
*************************************************************************************************/

#ifndef PRODUCER_SPOOLER_H
#define PRODUCER_SPOOLER_H

/**************************************** Headers **********************************************/
#include <pthread.h>

/* -------------------------------------------------------------------------------------------- */
/* Constantes                                                                                   */
/* -------------------------------------------------------------------------------------------- */

/* ---- Número máximo de búferes disponibles ---- */
#ifndef MAX_BUFFERS
#define MAX_BUFFERS 10   /* Puede ajustarse si el código original define otro valor */
#endif

/* -------------------------------------------------------------------------------------------- */
/* Prototipos de funciones                                                                      */
/* -------------------------------------------------------------------------------------------- */

/* **********************************************************************************************
 * Firma:     void *producer (void *arg)
 * Propósito: Función hilo productor. Escribe líneas de texto en los búferes compartidos.
 * Parámetros:
 *   - arg: puntero a entero que identifica el número del hilo productor.
 * Retorno:
 *   - void *: no se usa (retorno estándar para funciones de hilo).
 ********************************************************************************************** */
void *producer (void *arg);

/* **********************************************************************************************
 * Firma:     void *spooler (void *arg)
 * Propósito: Función hilo spooler. Extrae líneas del búfer y las imprime en pantalla.
 * Parámetros:
 *   - arg: no se utiliza (puede ser NULL).
 * Retorno:
 *   - void *: no se usa (hilo ejecuta en lazo infinito hasta ser cancelado).
 ********************************************************************************************** */
void *spooler (void *arg);

#endif /* PRODUCER_SPOOLER_H */
