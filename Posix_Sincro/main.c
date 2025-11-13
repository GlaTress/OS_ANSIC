/************************************************************************************************
*                               Pontificia Universidad Javeriana                                *
*                                                                                               *
* Autor:     [TU NOMBRE]                                                                        *
* Fecha:     [FECHA]                                                                            *
* Materia:   Sistemas Operativos                                                                *
* Profesor:  [NOMBRE DEL PROFESOR]                                                              *
* Objetivo:  Crear y gestionar los hilos productores y el hilo spooler que comparten buferes    *
*            de impresion utilizando pthreads.                                                  *
*************************************************************************************************
* HOW TO USE                                                                                    *
* --------------------------------------------------------------------------------------------- *
* 1. Compilar el proyecto:                                                                      *
*        gcc -Wall -pthread main.c producer_spooler.c -o spooler_app                            *
* 2. Ejecutar:                                                                                  *
*        ./spooler_app                                                                          *
* 3. Observar en pantalla como los productores generan lineas y el spooler las imprime.         *
*************************************************************************************************/

/**************************************** Headers **********************************************/

#include "producer_spooler.h"

char buf [MAX_BUFFERS] [100];
int buffer_index;
int buffer_print_index;

pthread_mutex_t buf_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t buf_cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t spool_cond = PTHREAD_COND_INITIALIZER;
int buffers_available = MAX_BUFFERS;
int lines_to_print = 0;

/* **********************************************************************************************
 * Firma:     int main (int argc, char **argv)
 * Proposito: Punto de entrada del programa. Inicializa los indices, crea los hilos productores
 *            y el hilo spooler, espera a que los productores terminen y cancela al spooler.
 * Parametros:
 *   - argc: numero de argumentos de linea de comandos (no se usan).
 *   - argv: arreglo de cadenas con los argumentos (no se usan).
 * Retorno:
 *   - int: codigo de salida del programa (0 si todo fue correcto).
 ********************************************************************************************** */
int main (int argc, char **argv){
    pthread_t tid_producer [10], tid_spooler;
    int i, r;

    buffer_index = buffer_print_index = 0;
    if ((r = pthread_create (&tid_spooler, NULL, spooler, NULL)) != 0) {
        fprintf (stderr, "Error = %d (%s)\n", r, strerror (r)); exit (1);
    }
    int thread_no [10];
    for (i = 0; i < 10; i++) {
        thread_no [i] = i;
        if ((r = pthread_create (&tid_producer [i], NULL, producer, (void *) &thread_no [i])) != 0) {
            fprintf (stderr, "Error = %d (%s)\n", r, strerror (r)); exit (1);
        }
    }
    for (i = 0; i < 10; i++)
        if ((r = pthread_join (tid_producer [i], NULL)) == -1) {
            fprintf (stderr, "Error = %d (%s)\n", r, strerror (r)); exit (1);
        }
    
    while (lines_to_print) sleep (1);
    if ((r = pthread_cancel (tid_spooler)) != 0) {
        fprintf (stderr, "Error = %d (%s)\n", r, strerror (r)); exit (1);
    }

    exit (0);
}
