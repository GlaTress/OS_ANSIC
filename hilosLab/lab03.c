/*************************************************************************************************************
*            Pontificia Universidad Javeriana                                                                *
*                                                                                                            *
* Autor:     Thomas Leal Puerta                                                                              *
* Fecha:     28/10/2025                                                                                      *
* Materia:   Sistemas Operativos                                                                             *
* Profesor:  John Jairo Corredor                                                                             *
* Objetivo:  Sincronización entre hilos utilizando mutex y condición para controlar el acceso al contador.   *
**************************************************************************************************************
*                                                                                                            *
* HOW TO USE                                                                                                 *
*                                                                                                            *
* HOW TO COMPILE TO PRODUCE EXECUTABLE PROGRAM:                                                              *
*   gcc -o lab03 lab03.c                                                                                     *
*                                                                                                            *
* HOW TO RUN THE PROGRAM:                                                                                    *
*   ./lab03                                                                                                  *
*************************************************************************************************************/

/************************************************* Headers **************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ALTO_CONTADOR_01 4
#define ALTO_CONTADOR_02 11
#define FIN_CONTADOR     20

pthread_mutex_t condition_Mutex = PTHREAD_MUTEX_INITIALIZER;  // Mutex para controlar las condiciones
pthread_mutex_t contador_Mutex  = PTHREAD_MUTEX_INITIALIZER;  // Mutex para el contador
pthread_cond_t  condition_Cond  = PTHREAD_COND_INITIALIZER;   // Condición para la sincronización
int counter = 0;  // Contador compartido

/************************************************************************************************************
/*                                                                                                          *
/*  void *contador01();                                                                                     *
/*                                                                                                          *
/*  Propósito: Incrementar el contador hasta el ALTO_CONTADOR_01, luego espera hasta ser avisado por el     *
/*             segundo hilo.                                                                                *
/*                                                                                                          *
/*  Parámetros: (ninguno)                                                                                   *
/*                                                                                                          *
/*  Retorno:   (void)                                                                                       *
/*                                                                                                          *
/************************************************************************************************************/
void *contador01(){
    for(;;){
        pthread_mutex_lock(&condition_Mutex);
        while(counter >= ALTO_CONTADOR_01 && counter <= ALTO_CONTADOR_02)
            pthread_cond_wait(&condition_Cond, &condition_Mutex);  // Espera hasta recibir la señal
        pthread_mutex_unlock(&condition_Mutex);

        pthread_mutex_lock(&contador_Mutex);
        counter++;  // Incrementa el contador
        printf("Valor de contador en funcion ==01==: %d \n", counter);
        pthread_mutex_unlock(&contador_Mutex);

        if(counter >= FIN_CONTADOR)
            return NULL;  // Finaliza si el contador alcanza el valor final
    }
}

/************************************************************************************************************
/*                                                                                                          *
/*  void *contador02();                                                                                     *
/*                                                                                                          *
/*  Propósito: Incrementar el contador hasta el ALTO_CONTADOR_02 y luego enviar una señal al primer hilo.   *
/*                                                                                                          *
/*  Parámetros: (ninguno)                                                                                   *
/*                                                                                                          *
/*  Retorno:   (void)                                                                                       *
/*                                                                                                          *
/************************************************************************************************************/
void *contador02(){
    for(;;){
        pthread_mutex_lock(&condition_Mutex);
        while(counter >= ALTO_CONTADOR_01 || counter <= ALTO_CONTADOR_02)
            pthread_cond_signal(&condition_Cond);  // Envía la señal a los hilos bloqueados
        pthread_mutex_unlock(&condition_Mutex);

        pthread_mutex_lock(&contador_Mutex);
        counter++;  // Incrementa el contador
        printf("Valor de contador en funcion ==02==: %d \n", counter);
        pthread_mutex_unlock(&contador_Mutex);

        if(counter >= FIN_CONTADOR)
            return NULL;  // Finaliza si el contador alcanza el valor final
    }
}

/************************************************************************************************************
/*                                                                                                          *
/*  void main();                                                                                            *
/*                                                                                                          *
/*  Propósito: Crear dos hilos que manejan el contador de manera sincronizada utilizando mutex y condición. *
/*                                                                                                          *
/*  Parámetros: (ninguno)                                                                                   *
/*                                                                                                          *
/*  Retorno:   0 si finaliza correctamente.                                                                 *
/*                                                                                                          *
/************************************************************************************************************/
void main() {
    pthread_t hilo01, hilo02;

    /* ---- Crear hilos ---- */
    pthread_create(&hilo01, NULL, contador01, NULL);  // Crear primer hilo
    pthread_create(&hilo02, NULL, contador02, NULL);  // Crear segundo hilo

    /* ---- Espera a que los hilos terminen ---- */
    pthread_join(hilo01, NULL);
    pthread_join(hilo02, NULL);

    /* ---- Imprimir valor final del contador ---- */
    printf("Valor final del contador: %d\n", counter);
}
