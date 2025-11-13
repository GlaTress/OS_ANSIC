/************************************************************************************************
*                               Pontificia Universidad Javeriana                                *
*                                                                                               *
* Autor:     [TU NOMBRE]                                                                        *
* Fecha:     [FECHA]                                                                            *
* Materia:   Sistemas Operativos                                                                *
* Profesor:  [NOMBRE DEL PROFESOR]                                                              *
* Objetivo:  Implementar las funciones productor y spooler que comparten un conjunto de búferes *
*            protegidos con mutex y variables de condición usando pthreads.                     *
************************************************************************************************/
/************************************************************************************************
* HOW TO USE                                                                                   *
* -------------------------------------------------------------------------------------------- *
* 1. Compilar junto con main.c y este archivo:                                                 *
*        gcc -Wall -pthread main.c producer_spooler.c -o spooler_app                           *
* 2. Ejecutar el programa generado:                                                            *
*        ./spooler_app                                                                         *
* 3. Diez hilos productores generarán mensajes que serán impresos por el hilo spooler.         *
************************************************************************************************/

/**************************************** Headers **********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "producer_spooler.h"

/* -------------------------------------------------------------------------------------------- */
/* Definición de variables globales                                                             */
/* -------------------------------------------------------------------------------------------- */

/* ---- Arreglo de búferes de salida ---- */
char buf [MAX_BUFFERS] [100];
int buffer_index;
int buffer_print_index;

/* ---- Sincronización entre productores y spooler ---- */
pthread_mutex_t buf_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t buf_cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t spool_cond = PTHREAD_COND_INITIALIZER;

/* ---- Contadores de estado ---- */
int buffers_available = MAX_BUFFERS;
int lines_to_print = 0;

/* -------------------------------------------------------------------------------------------- */
/* Implementación de funciones                                                                  */
/* -------------------------------------------------------------------------------------------- */

/* **********************************************************************************************
 * Firma:     void *producer (void *arg)
 * Propósito: Hilo productor. Escribe mensajes en los búferes cuando haya espacio disponible.
 * Parámetros:
 *   - arg: puntero a entero que indica el identificador lógico del hilo productor.
 * Retorno:
 *   - void *: no se utiliza; el hilo termina cuando completa sus iteraciones.
 ********************************************************************************************** */
void *producer (void *arg){
    int i, r;
    int my_id = *((int *) arg);
    int count = 0;

    for (i = 0; i < 10; i++) {

        /* ---- Sección crítica: solicitar acceso al búfer compartido ---- */
        if ((r = pthread_mutex_lock (&buf_mutex)) != 0) {
            fprintf (stderr, "Error = %d (%s)\n", r, strerror (r)); exit (1);
        }
            /* ---- Esperar mientras no haya búferes disponibles ---- */
            while (!buffers_available) 
                pthread_cond_wait (&buf_cond, &buf_mutex);

            /* ---- Reservar posición en el búfer circular ---- */
            int j = buffer_index;
            buffer_index++;
            if (buffer_index == MAX_BUFFERS)
                buffer_index = 0;
            buffers_available--;

            /* ---- Escribir mensaje en el búfer y actualizar contador de líneas ---- */
            sprintf (buf [j], "Thread %d: %d\n", my_id, ++count);
            lines_to_print++;

            /* ---- Despertar al spooler para que procese una nueva línea ---- */
            pthread_cond_signal (&spool_cond);

        /* ---- Salir de la sección crítica ---- */
        if ((r = pthread_mutex_unlock (&buf_mutex)) != 0) {
            fprintf (stderr, "Error = %d (%s)\n", r, strerror (r)); exit (1);
        }
    
        /* ---- Pausa entre producciones para simular trabajo ---- */
        sleep (1);
    }
}

/* **********************************************************************************************
 * Firma:     void *spooler (void *arg)
 * Propósito: Hilo spooler (consumidor). Toma líneas del búfer y las imprime en stdout.
 * Parámetros:
 *   - arg: no se usa (puede ser NULL).
 * Retorno:
 *   - void *: no retorna, corre en lazo infinito hasta ser cancelado.
 ********************************************************************************************** */
void *spooler (void *arg){
    int r;

    while (1) {  
        /* ---- Sección crítica: acceso al búfer compartido ---- */
        if ((r = pthread_mutex_lock (&buf_mutex)) != 0) {
            fprintf (stderr, "Error = %d (%s)\n", r, strerror (r)); exit (1);
        }
            /* ---- Esperar a que haya al menos una línea para imprimir ---- */
            while (!lines_to_print) 
                pthread_cond_wait (&spool_cond, &buf_mutex);

            /* ---- Imprimir la línea correspondiente del búfer circular ---- */
            printf ("%s", buf [buffer_print_index]);
            lines_to_print--;

            /* ---- Avanzar índice de impresión en el búfer circular ---- */
            buffer_print_index++;
            if (buffer_print_index == MAX_BUFFERS)
               buffer_print_index = 0;

            /* ---- Liberar un búfer y notificar a productores ---- */
            buffers_available++;
            pthread_cond_signal (&buf_cond);

        /* ---- Salir de la sección crítica ---- */
        if ((r = pthread_mutex_unlock (&buf_mutex)) != 0) {
            fprintf (stderr, "Error = %d (%s)\n", r, strerror (r)); exit (1);
        }

    }
}
