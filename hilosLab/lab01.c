/*************************************************************************************************************
*            Pontificia Universidad Javeriana                                                                *
*                                                                                                            *
* Autor:     Thomas Leal Puerta                                                                              *
* Fecha:     28/10/2025                                                                                      *
* Materia:   Sistemas Operativos                                                                             *
* Profesor:  John Jairo Corredor                                                                             *
* Objetivo:  Creación y ejecución de 2 hilos independientes utilizando pthreads, cada uno imprime un mensaje.*
**************************************************************************************************************
*                                                                                                            *
* HOW TO USE                                                                                                 *
*                                                                                                            *
* HOW TO COMPILE TO PRODUCE EXECUTABLE PROGRAM:                                                              *
*   gcc -o lab01 lab01.c                                                                                     *
*                                                                                                            *
* HOW TO RUN THE PROGRAM:                                                                                    *
*   ./lab01                                                                                                  *
**************************************************************************************************************/

/************************************************* Headers **************************************************/
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

/************************************************************************************************************
/*                                                                                                          *
/*  void *print_message_function(void *ptr);                                                                *
/*                                                                                                          *
/*  Propósito: Función que será ejecutada por cada hilo. Recibe un mensaje y lo imprime.                    *
/*                                                                                                          *
/*  Parámetros: ptr : puntero al mensaje a imprimir.                                                        *
/*                                                                                                          *
/*  Retorno:   (void)                                                                                       *
/*                                                                                                          *
/************************************************************************************************************/
void *print_message_function(void *ptr) {
    char *message;
    message = (char *) ptr;    // Asignación del mensaje recibido a la variable local
    printf("%s \n", message);  // Imprime el mensaje
}

/************************************************************************************************************/
/*                                                                                                          */
/*  int main();                                                                                             */
/*                                                                                                          */
/*  Propósito: Crear dos hilos, cada uno ejecutando print_message_function con mensajes distintos.          */
/*                                                                                                          */
/*  Parámetros: (ninguno)                                                                                   */
/*                                                                                                          */
/*  Retorno:   0 si finaliza correctamente.                                                                 */
/*                                                                                                          */
/************************************************************************************************************/
void main() {
    pthread_t thread1, thread2;
    char *message1 = "Thread 1";    // Mensaje para el primer hilo
    char *message2 = "Thread 2";    // Mensaje para el segundo hilo
    int iret1, iret2;

    /* ---- Crear hilos, cada uno ejecutando print_message_function ---- */
    iret1 = pthread_create(&thread1, NULL, print_message_function, (void*) message1);
    iret2 = pthread_create(&thread2, NULL, print_message_function, (void*) message2);

    /* ---- Mostrar los valores de retorno de la creación de hilos ---- */
    printf("Thread 1 returns: %d\n", iret1);
    printf("Thread 2 returns: %d\n", iret2);

    exit(0);  // Termina el programa
}
