/*************************************************************************************************************
*            Pontificia Universidad Javeriana                                                                *
*                                                                                                            *
* Autor:     Thomas Leal Puerta                                                                              *
* Fecha:     4 de Noviembre de 2025                                                                          *
* Materia:   Sistemas Operativos                                                                             *
* Profesor:  John Jairo Corredor, PhD                                                                        *
* Tema:      Introducción a OpenMP: configuración del número de hilos y uso de directivas paralelas.         *
*                                                                                                            *
* Objetivo:  Introduccion en laboratorio openMP clausulas y directivas para el programa
*                                                                                                            *
**************************************************************************************************************
*                                                                                                            *
* HOW TO USE                                                                                                 *
* ---------------------------------------------------------------------------------------------------------- *
* Compilar :  gcc -fopenmp lab02.c -o lab02                                                                  *
* Ejecutar :  ./lab02 numHilos                                                                               *
* Ejemplo  :  ./lab02 4                                                                                      *
*                                                                                                            *
* Descripción del programa:                                                                                  *
*  - Verifica el número de argumentos pasados por línea de comandos.                                         *
*  - Obtiene el número máximo de hilos disponibles en el sistema.                                            *
*  - Ajusta el número de hilos según el argumento ingresado por el usuario.                                 *
*  - Crea una región paralela donde cada hilo imprime su identificador.                                     *
*                                                                                                            *
*************************************************************************************************************/

/************************************************* Headers **************************************************/
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

/************************************************************************************************************/
/*                                                                                                          */
/*  int main(int argc, char *argv[]);                                                                       */
/*                                                                                                          */
/*  Propósito: Ejecutar un programa que permite establecer el número de hilos de ejecución paralela         */
/*             en OpenMP mediante un argumento de entrada.                                                  */
/*                                                                                                          */
/*  Parámetros: argc / argv : recibe el número de hilos a ejecutar (numHilos).                              */
/*                                                                                                          */
/*  Retorno:   0 si finaliza correctamente.                                                                 */
/*                                                                                                          */
/************************************************************************************************************/
int main (int argc, char *argv[]) {

    /* ---- Validar que el usuario ingrese el número correcto de argumentos ---- */
    if (argc != 2) {
        printf("ERROR\n\tUso correcto: $./ejecutable numHilos\n");
        exit(0);
    }

    /* ---- Convertir argumento de entrada a número entero ---- */
    int numHilos = (int) atoi(argv[1]);

    /* ---- Obtener el número máximo de hilos disponibles en el sistema ---- */
    int maxHilos = omp_get_max_threads();
    printf("OpenMP ejecutando en cores = %d hilos disponibles\n", maxHilos);

    /* ---- Fijar el número de hilos solicitado por el usuario ---- */
    omp_set_num_threads(numHilos);

    /* ---- Región paralela controlada: se crean numHilos hilos ---- */
    #pragma omp parallel
    {
        /* ---- Cada hilo imprime su identificador ---- */
        printf("Hello world desde el thread %d\n", omp_get_thread_num());
    }

    /* ---- Finalización del programa principal ---- */
    return 0;
}

