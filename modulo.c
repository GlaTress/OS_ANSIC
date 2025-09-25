
/*-- Se Incluyen Interfaces necesarias---------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include "modulo.h"

/*-- Se declaran los datos gloables ini y fin de la estructura timeval-------------------------- */
struct timeval ini, fin;

/**************************************************************************/
/*  Function: InicioMuestra                                               */
/*                                                                        */
/*  Purpose: Captura el tiempo de inicio para mediciones de duración.     */
/*           Almacena el instante actual en la variable global ini.       */
/*                                                                        */
/*  Parameters: Ninguno.                                                  */
/*                                                                        */
/*  Returns: void.                                                        */
/*                                                                        */
/**************************************************************************/
void InicioMuestra(){
  gettimeofday(&ini, (void *)0);
}

/**************************************************************************/
/*  Function: FinMuestra                                                  */
/*                                                                        */
/*  Purpose: Captura el tiempo final, calcula la diferencia respecto a    */
/*           ini y muestra por printf el tiempo transcurrido.             */
/*                                                                        */
/*  Parameters: Ninguno.                                                  */
/*                                                                        */
/*  Returns: void.                                                        */
/*                                                                        */
/**************************************************************************/
void FinMuestra(){
    /*-- Se captura el tiempo final------------------------------------------ */
  gettimeofday(&fin, (void *)0);
    /*-- Se calcula la diferencia entre el tiempo final y el tiempo inicial-- */
  fin.tv_usec -= ini.tv_usec;
  fin.tv_sec  -= ini.tv_sec;
    /*-- Se ajusta el tiempo final------------------------------------------- */
  double tiempo = (double) (fin.tv_sec*1000000 + fin.tv_usec);
    /*-- Se imprime el tiempo transcurrido----------------------------------- */
  printf("%9.0f \n", tiempo);
}

/**************************************************************************/
/*  Function: iniMatriz                                                   */
/*                                                                        */
/*  Purpose: Inicializa dos arreglos unidimensionales que representan     */
/*           matrices cuadradas n x n .                                   */
/*                                                                        */
/*  Parameters:                                                           */
/*    n   - (int) tamaño de la matriz (n filas, n columnas).              */
/*    m1  - (double*) puntero al primer arreglo  n*n elementos.           */
/*    m2  - (double*) puntero al segundo arreglo  n*n elementos.          */
/*                                                                        */
/*  Returns: void.                                                        */
/*                                                                        */
/**************************************************************************/
void iniMatriz(int n, double *m1, double *m2){
    /*-- Se inicializan las matrices ------------------------------------ */
    for(int i=0; i<n*n; i++){
            /*-- Se inicializan los elementos de las matrices ----------- */
          m1[i] = i*2.3 + 1.3;
          m2[i] = i*2.3;
  }
};

/**************************************************************************/
/*  Function: imprMatrices                                                */
/*                                                                        */
/*  Purpose: Imprime por stdout el contenido de una matriz representada   */
/*           como arreglo lineal de tamaño n x n.                         */
/*                                                                        */
/*  Parameters:                                                           */
/*    n      - (int) tamaño de la matriz (n filas, n columnas).           */
/*    matriz - (double*) puntero al arreglo con al menos n*n elementos.   */
/*                                                                        */
/*  Returns: void.                                                        */
/*                                                                        */
/**************************************************************************/
void imprMatrices(int n, double *matriz){
    if(n<9){
        printf("\n-------------------------------------------------------\n");
    for(int i=0; i<n*n; i++){
                if(i%n==0) printf("\n");
          printf(" %f ", matriz[i]);
   }
    } else {
        printf("\n-------------------------------------------------------\n");
    }
};

