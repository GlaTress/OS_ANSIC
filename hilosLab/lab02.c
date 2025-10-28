/*************************************************************************************************************
*            Pontificia Universidad Javeriana                                                                *
*                                                                                                            *
* Autor:     Thomas Leal Puerta                                                                              *
* Fecha:     28/10/2025                                                                                      *
* Materia:   Sistemas Operativos                                                                             *
* Profesor:  John Jairo Corredor                                                                             *
* Objetivo:  Crear múltiples hilos con mutex para proteger el acceso concurrente a una variable compartida. *
**************************************************************************************************************
*                                                                                                            *
* HOW TO USE                                                                                                 *
*                                                                                                            *
* HOW TO COMPILE TO PRODUCE EXECUTABLE PROGRAM:                                                              *
*   gcc -o lab02 lab02.c                                                                                     *
*                                                                                                            *
* HOW TO RUN THE PROGRAM:                                                                                    *
*   ./lab02                                                                                                  *
*************************************************************************************************************/

/************************************************* Headers **************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 10  // Definición de cantidad de hilos

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;  // Inicialización del mutex
int counter = 0;  // Contador compartido entre hilos

/************************************************************************************************************
/*                                                                                                          *
/*  void *thread_function(void *arg);                                                                       *
/*                                                                                                          *
/*  Propósito: Función que ejecutarán los hilos. Incrementa el contador de forma segura usando mutex.       *
/*                                                                                                          *
/*  Parámetros: arg : índice del hilo que se crea.                                                          *
/*                                                                                                          *
/*  Retorno:   (void)                                                                                       *
/*                                                                                                          *
/************************************************************************************************************/
void *thread_function(void *arg) {
    int i = *(int *)(arg);  // Obtiene el número del hilo
    printf("Thread number: %d | Thread ID %ld\n", i, pthread_self());  // Imprime el número e ID del hilo
    pthread_mutex_lock(&mutex1);  // Bloquea el mutex antes de modificar la variable compartida
    counter++;  // Incrementa el contador
    pthread_mutex_unlock(&mutex1);  // Desbloquea el mutex
}

/************************************************************************************************************
/*                                                                                                          *
/*  void main();                                                                                            *
/*                                                                                                          *
/*  Propósito: Crear NTHREADS hilos que incrementan un contador compartido utilizando un mutex.             *
/*                                                                                                          *
/*  Parámetros: (ninguno)                                                                                   *
/*                                                                                                          *
/*  Retorno:   0 si finaliza correctamente.                                                                 *
/*                                                                                                          *
/************************************************************************************************************/
void main() {
    pthread_t thread_id[NTHREADS];  // Array para almacenar los identificadores de los hilos
    int i, j;
    
    /* ---- Crear hilos ---- */
    for(i = 0; i < NTHREADS; i++) {
        pthread_create(&thread_id[i], NULL, thread_function, &i);  // Crear hilos y pasar el índice
    }

    /* ---- Mostrar el valor final del contador ---- */
    printf("Final counter value: %d\n", counter);
}
