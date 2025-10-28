/*************************************************************************************************************
*            Pontificia Universidad Javeriana                                                                *
*                                                                                                            *
* Autor:     Thomas Leal Puerta                                                                              *
* Fecha:     28/10/2025                                                                                      *
* Materia:   Sistemas Operativos                                                                             *
* Profesor:  John Jairo Corredor                                                                             *
* Objetivo:  Crear múltiples hilos para ejecutar trabajos concurrentes, con mutex para sincronización.       *
**************************************************************************************************************
*                                                                                                            *
* HOW TO USE                                                                                                 *
*                                                                                                            *
* HOW TO COMPILE TO PRODUCE EXECUTABLE PROGRAM:                                                              *
*   gcc -o lab04 lab04.c                                                                                     *
*                                                                                                            *
* HOW TO RUN THE PROGRAM:                                                                                    *
*   ./lab04                                                                                                  *
*************************************************************************************************************/

/************************************************* Headers **************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

pthread_t tid[3];  /* --- Array de identificadores de hilos -----*/ 
int counter;   /* --- Contador para el número de trabajos -----*/

pthread_mutex_t lock;  // Mutex para sincronización

/************************************************************************************************************
/*                                                                                                          *
/*  void *compute(void *arg);                                                                               *
/*                                                                                                          *
/*  Propósito: Función que se ejecutará en cada hilo. Incrementa el contador y simula un trabajo.           *
/*                                                                                                          *
/*  Parámetros: arg : puntero a un argumento, no utilizado en esta función.                                 *
/*                                                                                                          *
/*  Retorno:   (void)                                                                                       *
/*                                                                                                          *
/************************************************************************************************************/
void *compute(void *arg)
{
    unsigned long i = 0;

    /* ---- Bloqueo del mutex para acceder al contador de manera segura ---- */
    pthread_mutex_lock(&lock);
    counter += 1;  // Incrementa el contador de trabajos
    printf("\nJob %d has started\n", counter);
    pthread_mutex_unlock(&lock);  // Desbloqueo del mutex

    /* ---- Simulación de trabajo (ciclo de espera) ---- */
    for(i = 0; i < 0xFFFFFFFF; i++);

    printf("\nJob %d has finished\n", counter);

    return NULL;
}

/************************************************************************************************************
/*                                                                                                          *
/*  int main(void);                                                                                         *
/*                                                                                                          *
/*  Propósito: Crear 3 hilos que ejecutan la función compute. Cada hilo simula un trabajo.                  *
/*                                                                                                          *
/*  Parámetros: (ninguno)                                                                                   *
/*                                                                                                          *
/*  Retorno:   0 si finaliza correctamente.                                                                 *
/*                                                                                                          *
/************************************************************************************************************/
int main(void)
{
    int i = 0;
    int error;

    /* ---- Inicializar mutex ---- */
    pthread_mutex_init(&lock, NULL);

    /* ---- Crear 3 hilos ---- */
    while(i < 3)
    {
        error = pthread_create(&(tid[i]), NULL, &compute, NULL);
        if (error != 0)
            printf("\nThread can't be created: [%s]", strerror(error));  // Manejo de error en creación de hilos
        i++;
    }

    /* ---- Esperar a que todos los hilos finalicen ---- */
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_join(tid[2], NULL);

    /* ---- Destruir el mutex ---- */
    pthread_mutex_destroy(&lock);

    return 0;
}
