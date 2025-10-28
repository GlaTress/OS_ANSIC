/*************************************************************************************************************
*            Pontificia Universidad Javeriana                                                                *
*                                                                                                            *
* Autor:     Thomas Leal Puerta                                                                              *
* Fecha:     28/10/2025                                                                                      *
* Materia:   Sistemas Operativos                                                                             *
* Profesor:  John Jairo Corredor                                                                             *
* Objetivo:  Crear hilos para calcular la suma de los cuadrados de los números con mutex para sincronización.*
**************************************************************************************************************
*                                                                                                            *
* HOW TO USE                                                                                                 *
*                                                                                                            *
* HOW TO COMPILE TO PRODUCE EXECUTABLE PROGRAM:                                                              *
*   gcc -o lab06 lab06.c                                                                                     *
*                                                                                                            *
* HOW TO RUN THE PROGRAM:                                                                                    *
*   ./lab06                                                                                                  *
*************************************************************************************************************/

/************************************************* Headers **************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>

pthread_mutex_t acumuladoMutex = PTHREAD_MUTEX_INITIALIZER;  // Mutex para sincronización
int acumulado = 0;  // Variable compartida entre los hilos

/************************************************************************************************************
/*                                                                                                          *
/*  void *cuadrados(void *x);                                                                               *
/*                                                                                                          *
/*  Propósito: Calcular el cuadrado del número recibido y sumarlo a la variable global acumulado de manera  *
/*             segura utilizando un mutex.                                                                  *
/*                                                                                                          *
/*  Parámetros: x : valor entero recibido como argumento (número a elevar al cuadrado).                     *
/*                                                                                                          *
/*  Retorno:   (void)                                                                                       *
/*                                                                                                          *
/************************************************************************************************************/
void *cuadrados(void *x) {
    int xi = (intptr_t)x;

    /* ---- Bloquear el mutex antes de modificar la variable compartida ---- */
    pthread_mutex_lock(&acumuladoMutex);
    acumulado += xi * xi;  // Suma el cuadrado de xi al acumulado
    pthread_mutex_unlock(&acumuladoMutex);  // Desbloquea el mutex

    return NULL;
}

/************************************************************************************************************
/*                                                                                                          *
/*  int main ();                                                                                            *
/*                                                                                                          *
/*  Propósito: Crear 20 hilos para calcular la suma de los cuadrados de los números del 1 al 20, con        *
/*             sincronización utilizando mutex.                                                             *
/*                                                                                                          *
/*  Parámetros: (ninguno)                                                                                   *
/*                                                                                                          *
/*  Retorno:   0 si finaliza correctamente.                                                                 *
/*                                                                                                          *
/************************************************************************************************************/
int main (){
    pthread_t hilos[20];  // Array de hilos

    /* ---- Crear 20 hilos ---- */
    for(int i = 0; i < 20; i++) {
        pthread_create(&hilos[i], NULL, cuadrados, (void *)(intptr_t)(i+1));
    }

    /* ---- Esperar a que todos los hilos terminen ---- */
    for(int i = 0; i < 20; i++) {
        void *resultado;
        pthread_join(hilos[i], NULL);  // Espera que cada hilo termine
    }

    /* ---- Imprimir el resultado final ---- */
    printf("Sumas cuadradas = %d\n", acumulado);
    return 0;
}
