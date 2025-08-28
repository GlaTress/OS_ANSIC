/*************************************************************************************************************
*            Pontificia Universidad Javeriana                                                                *
*                                                                                                            *
* Autor:     Thomas Leal Puerta                                                                              *
* Fecha:     27 de Agosto, 2025                                                                              *
* Materia:   Sistemas Operativos                                                                             *
* Profesor:  John Jairo Corredor                                                                             *
* Objetivo:  Implementacion de Challenge3                                                                    *
*                                                                                                            *
**************************************************************************************************************
*                                                                                                            *
**************************************************************************************************************
*                                                                                                            *
* HOW TO USE                                                                                                 *
*                                                                                                            *
* HOW TO COMPILE TO PRODUCE EXECUTABLE PROGRAM:                                                              *
*   Linux/macOS:          gcc challenge3.c -o reto3                                                          *
*   Windows (MinGW):      gcc challenge3.c -o reto3.exe                                                      *
*                                                                                                            *
* HOW TO RUN THE PROGRAM:                                                                                    *
*   Linux/macOS:          ./reto3                                                                            *
*   Windows (CMD):        reto3.exe                                                                          *
*   Windows (PowerShell): .\reto3.exe                                                                        *
*************************************************************************************************************/

/************************************************* Headers **************************************************/
#include <stdio.h>
#include <stdlib.h>

/************************************************************************************************************/
/*                                                                                                          */
/*  int main();                                                                                             */
/*                                                                                                          */
/*  Propósito: Demostrar asignación dinámica, copia e impresión de cadenas                                  */
/*             en C usando malloc , printf y free.                                                          */
/*                                                                                                          */
/*  Retorno:   0 si finaliza correctamente.                                                                 */
/*                                                                                                          */
/************************************************************************************************************/
int main(){
  /* ---- Se declara un apuntador a int --------------------------------------------------------------- */
  int *ptr;
  /* ---- Se reserva memoria para 15 enteros ---------------------------------------------------------- */
  ptr = malloc(15 * sizeof(*ptr));
  /* ---- Se verifica si la asignación fue exitosa ---------------------------------------------------- */
  if(ptr != NULL){
    /* ---- Se asigna el valor 480 al elemento en la posición 5 del arreglo --------------------------- */
    *(ptr + 5) = 480;
    /* ---- Se imprime el valor del elemento en la posición 5 del arreglo ----------------------------- */
    printf("ptr[5] = %d\n", ptr[5]);
  }
  /* ---- Se libera la memoria reservada para el arreglo ---------------------------------------------- */
  free(ptr);
  return 0;
}
