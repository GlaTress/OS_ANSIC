/*************************************************************************************************************
*            Pontificia Universidad Javeriana                                                                *
*                                                                                                            *
* Autor:     Thomas Leal Puerta                                                                              *
* Fecha:     6 de Noviembre de 2025                                                                          *
* Materia:   Sistemas Operativos                                                                             *
* Profesor:  John Jairo Corredor, PhD                                                                        *
* Tema:      OpenMP, Sumatoria paralela con reducción y medición de tiempo                                   *
*                                                                                                            *
* Objetivo:  Implementar una sumatoria paralela usando la función seno, recibiendo por línea de comandos:    *
*            - Número de hilos (numHilos)                                                                    *
*            - Número de iteraciones (N)                                                                     *
*            Además, medir el tiempo total de ejecución e imprimir la sumatoria resultante.                  *
*                                                                                                            *
**************************************************************************************************************
*                                                                                                            *
* HOW TO USE                                                                                                 *
* ---------------------------------------------------------------------------------------------------------- *
* Compilar :  gcc -fopenmp lab05.c -o lab05 -lm                                                              *
* Ejecutar :  ./lab05 numHilos N                                                                             *
* Ejemplo  :  ./lab05 4 30000                                                                                *
*                                                                                                            *
*************************************************************************************************************/

/************************************************* Headers **************************************************/
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <math.h>

/************************************************************************************************************/
/*                                                                                                          */
/*  double funcion(int i);                                                                                  */
/*                                                                                                          */
/*  Propósito: Para un índice i, calcula la sumatoria de senos desde un rango determinado.                  */
/*                                                                                                          */
/*  Parámetros: i : índice base que define el rango de inicio y fin de la sumatoria.                        */
/*                                                                                                          */
/*  Retorno:   Resultado acumulado de la sumatoria de senos en el rango definido.                           */
/*                                                                                                          */
/************************************************************************************************************/
double funcion(int i) {

    /* ---- Definición de rango de la sumatoria ---- */
    int j;
    int start  = i * (i + 1) / 2;
    int finish = start + i;
    double return_val = 0.0;

    /* ---- Calcular la sumatoria parcial usando la función seno ---- */
    for (j = start; j <= finish; j++) {
        return_val += sin((double) j);
    }

    /* ---- Retornar el resultado acumulado ---- */
    return return_val;
}

/************************************************************************************************************/
/*                                                                                                          */
/*  int main(int argc, char *argv[]);                                                                       */
/*                                                                                                          */
/*  Propósito: Ejecutar la sumatoria de forma paralela controlando la cantidad de hilos e iteraciones       */
/*             mediante argumentos de línea de comandos. Medir el tiempo total y mostrar resultados.        */
/*                                                                                                          */
/*  Parámetros: argc / argv :                                                                               */
/*              argv[1] = número de hilos, argv[2] = cantidad de repeticiones del bucle for.                */
/*                                                                                                          */
/************************************************************************************************************/
int main(int argc, char* argv[]) {

    /* ---- Validar cantidad de argumentos ---- */
    if (argc < 2 || argc > 3) {
        printf("ERROR\n\tUso correcto: ./lab05 numHilos [N]\n");
        printf("\tEjemplo: ./lab05 4 30000\n");
        exit(0);
    }

    /* ---- Asignar argumentos ---- */
    int numHilos = atoi(argv[1]);
    long N = 30000; /* valor por defecto */

    /* ---- Si el usuario proporciona un segundo parámetro, actualizar N ---- */
    if (argc == 3) {
        N = atol(argv[2]);
    }

    /* ---- Validar que los valores sean correctos ---- */
    if (numHilos <= 0 || N <= 0) {
        printf("ERROR: Los valores deben ser mayores que 0.\n");
        printf("\tEjemplo: ./lab05 4 30000\n");
        exit(0);
    }

    /* ---- Configurar número de hilos ---- */
    omp_set_num_threads(numHilos);

    /* ---- Acumulador global de la sumatoria ---- */
    double sumatoria = 0.0;

    /* ---- Variables para medir tiempo ---- */
    double t_inicio, t_final, tiempo_total;

    /* ---- Mostrar configuración de ejecución ---- */
    printf("  Hilos del sistema  : %d\n", omp_get_max_threads());
    printf("  Hilos solicitados  : %d\n", numHilos);
    printf("  Iteraciones (N)    : %ld\n\n", N);

    /* ---- Registrar el tiempo inicial ---- */
    t_inicio = omp_get_wtime();

    /* ---- Región paralela con reducción ---- */
    #pragma omp parallel
    {
        /* ---- Todos los hilos participan en el cálculo ---- */
        #pragma omp for reduction(+:sumatoria) schedule(static)
        for (int i = 0; i < N; i++) {
            sumatoria += funcion((int)i);
        }
    }

    /* ---- Registrar el tiempo final ---- */
    t_final = omp_get_wtime();

    /* ---- Calcular tiempo total ---- */
    tiempo_total = t_final - t_inicio;

    /* ---- Imprimir resultados ---- */
    printf("=======Resultado final=======\n\n");
    printf("  Valor Sumatorio de función SENO: %.6f\n", sumatoria);
    printf("  Tiempo de ejecución: %.6f segundos\n", tiempo_total);

    /* ---- Finalización del programa ---- */
    return 0;
}
