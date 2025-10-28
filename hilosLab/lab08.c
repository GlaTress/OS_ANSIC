/*************************************************************************************************************
*            Pontificia Universidad Javeriana                                                                *
*                                                                                                            *
* Autor:     Thomas Leal Puerta                                                                              *
* Fecha:     28/10/2025                                                                                      *
* Materia:   Sistemas Operativos                                                                             *
* Profesor:  John Jairo Corredor                                                                             *
* Objetivo:  Uso de mutex y condiciones para sincronizar el valor entre dos hilos.                           *
**************************************************************************************************************
*                                                                                                            *
* HOW TO USE                                                                                                 *
*                                                                                                            *
* HOW TO COMPILE TO PRODUCE EXECUTABLE PROGRAM:                                                              *
*   gcc -o lab08 lab08.c                                                                                     *
*                                                                                                            *
* HOW TO RUN THE PROGRAM:                                                                                    *
*   ./lab08                                                                                                  *
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
bool notificar = false;  // Variable para notificación

/************************************************************************************************************
/*                                                                                                          *
/*  void *reportar(void *nousado);                                                                          *
/*                                                                                                          *
/*  Propósito: Función que espera la notificación antes de imprimir el valor.                               *
/*                                                                                                          *
/*  Parámetros: nousado : no utilizado, solo para cumplir con la firma de la función de pthread.            *
/*                                                                                                          *
/*  Retorno:   (void)                                                                                       *
/*                                                                                                          *
/************************************************************************************************************/
void *reportar(void *nousado){
        pthread_mutex_lock(&mutexVar);
        while(!notificar)  // Espera hasta recibir la señal
                pthread_cond_wait(&varCondition, &mutexVar);
        pthread_mutex_unlock(&mutexVar);

        printf("El valor es: %d \n", valor);  // Imprime el valor
        return NULL;
}

/************************************************************************************************************
/*                                                                                                          *
/*  void *asignar(void *nousado);                                                                           *
/*                                                                                                          *
/*  Propósito: Cambia el valor y notifica al hilo reportador para que imprima.                              *
/*                                                                                                          *
/*  Parámetros: nousado : no utilizado, solo para cumplir con la firma de la función de pthread.            *
/*                                                                                                          *
/*  Retorno:   (void)                                                                                       *
/*                                                                                                          *
/************************************************************************************************************/
void *asignar(void *nousado){
        valor = 20;  // Asigna el nuevo valor
        
        pthread_mutex_lock(&mutexVar);
        notificar = true;  // Marca la variable para que el hilo reportador imprima
        pthread_cond_signal(&varCondition);  // Envía la señal
        pthread_mutex_unlock(&mutexVar);
        
        return NULL;
}

/************************************************************************************************************
/*                                                                                                          *
/*  int main ();                                                                                            *
/*                                                                                                          *
/*  Propósito: Crear dos hilos, uno reporta el valor y otro lo asigna, sincronizados usando condiciones.    *
/*                                                                                                          *
/*  Parámetros: (ninguno)                                                                                   *
/*                                                                                                          *
/*  Retorno:   0 si finaliza correctamente.                                                                 *
/*                                                                                                          *
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
