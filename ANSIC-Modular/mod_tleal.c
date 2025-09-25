/****************************************************************************************************
 * Fecha    : 24 de septiembe, 2025                                                                 *
 * Autor    : Thomas Leal Puerta                                                                    *
 * Materia  : Sistemas Operativos                                                                   *
 * Tema     : Generación de programa principal para la Multiplicación de matrices.                  *
 * Objetivo : Hacer una metodología para la implementación de la multiplicación de matrices.        *
 *            La idea principal, es construir paso a paso la implementación.                        *
 *                                                                                                  *
 *--------------------------------------------------------------------------------------------------*
 *                                                                                                  *
 * Inicialmente se genera el programa o código de forma general.                                    *
 * Posteriormente, se toma como enfoque la programación modular.                                    *
 *                                                                                                  *
 *--------------------------------------------------------------------------------------------------*
 *                                                                                                  *
 * A continuación se describen los paso:                                                            *
 *  - Reserva de memoria                                                                            *
 *      - Creación de punteros para matrices del tipo doble                                         *
 *      - Asignación de memoria                                                                     *
 *      - Ingreso de argumentos de entrada (Dimensión matriz, número de hilos)                      *
 *      - Validación argumentos de entrada                                                          *
 *      - Inicializar las matrices                                                                  *
 *      - Imprimir las matrices                                                                     *
 *      - Función para inicializar las matrices                                                     *
 *      - Función para imprimir las matrices                                                        *
 *      - Algoritmo clásico de multiplicación matrices                                              *
 *  - Se verifica el resultado                                                                      *
 *      - Función para multiplicación las matrices                                                  *
 *      - Crear estructura de datos que encapsule los argumentos de entrada de la función MM        *
 *                                                                                                  *
 *--------------------------------------------------------------------------------------------------*
 *                                                                                                  *
 * Implementación de paralelismo: resolución de la multiplicación de matrices                       *
 *  - Se pasa a globales las matrices                                                               *
 *  - Encapsular los datos para enviarlos a la función NxN                                          *
 *  - Se desencapsulan los datos dentro de la función NxN (descomprimen)                            *
 *                                                                                                  *
 ****************************************************************************************************/


/* ---- Se Incluyen Interfaces necesarias---------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include "modulo.h"

/* ---- Se declaran las matrices globales---------------------------------------------------------- */
double *mA, *mB, *mC;

/******************************************************************************/
/*                                                                            */
/*  int main(int argc, char *argv[]);                                         */
/*                                                                            */
/*  Purpose: Leer N desde linea de comandos, reservar e inicializar matrices  */
/*           A, B, C de tamanno NxN, calcular C = A × B y mostrar resultados. */
/*                                                                            */
/*  Return:  0  en ejecucion correcta.                                        */
/*           -1 en caso de argumentos invalidos, N <= 0 o fallo de memoria.   */
/*                                                                            */
/*  Plan (3 partes):                                                          */
/*    Part 1: Validacion e Inicializacion                                     */
/*                                                                            */
/*    Part 2: Computo y liberacion                                            */
/*                                                                            */
/******************************************************************************/
int main(int argc, char *argv[]) {

    /* ---- Parte 1 ----------------------------------------------------------------------------- */

    /* ---- Se verifica que el número de argumentos sea correcto--------------------------------- */
    if(argc<=2){
        printf("Numero argumentos incorrectos\n");
        printf("\n\t $ejecutable.exe DIM \n");
        return -1;
    }

    /* ---- Se obtiene la dimensión de la matriz------------------------------------------------ */
    int N = (int) atof(argv[1]);
    if(N<=0){
        printf("\n Valores deben ser mayor que cero\n");
        return -1;
    };

    /* ---- Se reserva memoria para las matrices------------------------------------------------ */
    mA = (double *) malloc(N*N*sizeof(double));
    mB = (double *) malloc(N*N*sizeof(double));
    mC = (double *) calloc(N*N,sizeof(double));

    /* ---- Se inicializan las matrices--------------------------------------------------------- */
  iniMatriz(N, mA, mB);
    /* ---- Se imprimen las matrices------------------------------------------------------------ */
  imprMatrices(N, mA);
  imprMatrices(N, mB);

    /* ---- Parte 1 ---------------------------------------------------------------------------- */

    /* ---- Se realiza la multiplicación de matrices-------------------------------------------- */
     for(int i=0; i<0; i++){
        for(int j=0; j<N; j++){

            /* ---- Declaración de temporales y punteros a A y B --------------------------------*/
            double sumaTemp, *pA, *pB;
            /* ---- Inicializa temporal acumulador a 0.0 --------------------------------------- */
            sumaTemp = 0.0;
            /* ---- pA apunta al inicio de la fila i en A -------------------------------------- */
            pA = mA + i*N;
             /* ---- pB apunta al elemento (0,j) de B. ----------------------------------------- */
            pB = mB + j;

            for(int k=0; k<N; k++, pA++, pB+=N){
                /* ---- Se acumula el producto de los elementos de A y B. ---------------------- */
                sumaTemp += *pA * *pB;
            }
            mC[j+i*N] = sumaTemp;
        }
    }
    
    /* ---- Se imprimen las matrices------------------------------------------------------------ */
    imprMatrices(N, mB);

    printf("\n\tFin del programa.............!\n");

    /* ---- Se libera la memoria reservada para las matrices------------------------------------ */
    free(mA);
    free(mB);
    free(mC);

    return 0;

}
