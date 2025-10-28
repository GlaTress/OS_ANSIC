/*************************************************************************************************************
*            Pontificia Universidad Javeriana                                                                *
*                                                                                                            *
* Autor:     (Tu nombre o el de los autores)                                                                 *
* Fecha:     (Fecha del desarrollo)                                                                          *
* Materia:   (Materia)                                                                                       *
* Profesor:  (Nombre del profesor)                                                                           *
* Objetivo:  Sincronizar hilos utilizando condiciones y mutex.                                               *
**************************************************************************************************************
*                                                                                                            *
* HOW TO USE                                                                                                 *
*                                                                                                            *
* HOW TO COMPILE TO PRODUCE EXECUTABLE PROGRAM:                                                              *
*   gcc -o lab07 lab07.c                                                                                     *
*                                                                                                            *
* HOW TO RUN THE PROGRAM:                                                                                    *
*   ./lab07                                                                                                  *
*************************************************************************************************************/

/************************************************* Headers **************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include <stdbool.h>

pthread_cond_t varCondition = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutexVar = PTHREAD_MUTEX_INITIALIZER;

int valor = 100;  // Valor compartido
bool notificar = false;  // Variable de control para notificar

/************************************************************************************************************
/*                                                                                                          *
/*  void *reportar(void *nousado);                                                                          *
/*                                                                                                          *
/*  Propósito: Función que imprime el valor cuando es notificado.                                           *
/*                                                                                                          *
/*  Parámetros: nousado : no utilizado, solo para cumplir con la firma de la función de pthread.            *
/*                                                                                                          *
/*  Retorno:   (void)                                                                                       *
/*                                                                                                          *
/************************************************************************************************************/
void *reportar(void *nousado){
        printf("El valor es: %d \n", valor);  // Imprime el valor actual
        return NULL;
}

/************************************************************************************************************
/*                                                                                                          *
/*  void *asignar(void *nousado);                                                                           *
/*                                                                                                          *
/*  Propósito: Asigna un nuevo valor y notifica al hilo reportador utilizando una condición.                *
/*                                                                                                          *
/*  Parámetros: nousado : no utilizado, solo para cumplir con la firma de la función de pthread.            *
/*                                                                                                          *
/*  Retorno:   (void)                                                                                       *
/*                                                                                                          *
/************************************************************************************************************/
void *asignar(void *nousado){
        valor = 20;  // Asigna un nuevo valor

        /* ---- Bloqueo para notificar al hilo reportador ---- */
        pthread_mutex_lock(&mutexVar);
        notificar = true;
        pthread_cond_signal(&varCondition);  // Envía la señal
        pthread_mutex_unlock(&mutexVar);

        return NULL;
}

/************************************************************************************************************/
/*                                                                                                          */
/*  int main ();                                                                                             */
/*                                                                                                          */
/*  Propósito: Crear dos hilos para reportar y asignar valores, sincronizados mediante condiciones y mutex.  */
/*                                                                                                          */
/*  Parámetros: (ninguno)                                                                                   */
/*                                                                                                          */
/*  Retorno:   0 si finaliza correctamente.                                                                  */
/*                                                                                                          */
/************************************************************************************************************/
int main (){
        pthread_t reporte, asigne;
        pthread_create(&reporte, NULL, reportar, NULL);  // Crear hilo reportador
        pthread_create(&asigne, NULL, asignar, NULL);  // Crear hilo asignador

        void *nousado;
	pthread_join(reporte, &nousado);  // Espera hilo reportador
	pthread_join(asigne, &nousado);  // Espera hilo asignador

	return 0;
}
