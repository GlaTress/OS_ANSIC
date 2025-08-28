/*************************************************************************************************************
*            Pontificia Universidad Javeriana                                                                *
*                                                                                                            *
* Autor:     Thomas Leal Puerta                                                                              *
* Fecha:     27 de Agosto, 2025                                                                              *
* Materia:   Sistemas Operativos                                                                             *
* Profesor:  John Jairo Corredor                                                                             *
* Objetivo:  Implementacion de Challenge4                                                                    *
*                                                                                                            *
**************************************************************************************************************
*                                                                                                            *
**************************************************************************************************************
*                                                                                                            *
* HOW TO USE                                                                                                 *
*                                                                                                            *
* HOW TO COMPILE TO PRODUCE EXECUTABLE PROGRAM:                                                              *
*   Linux/macOS:          gcc challenge4.c -o reto4                                                          *
*   Windows (MinGW):      gcc challenge4.c -o reto4.exe                                                      *
*                                                                                                            *
* HOW TO RUN THE PROGRAM:                                                                                    *
*   Linux/macOS:          ./reto4                                                                            *
*   Windows (CMD):        reto4.exe                                                                          *
*   Windows (PowerShell): .\reto4.exe                                                                        *
*************************************************************************************************************/

/************************************************* Headers **************************************************/

#include <stdio.h>
#include <stdlib.h>

/************************************************************************************************************/
/*                                                                                                          */
/*  int main();                                                                                             */
/*                                                                                                          */
/*  Propósito: Demostrar asignación dinámica, copia e impresión de cadenas                                  */
/*             en C usando calloc, scanf, printf y free.                                                   */
/*                                                                                                          */
/*  Retorno:   0 si finaliza correctamente.                                                                 */
/*                                                                                                          */
/************************************************************************************************************/
int main(){
  /* ---- Se declara tres enteros y un apuntador a entero -------------------------------------- */
  int n, i, *ptr, sum = 0;
  printf("Enter number of elements: ");
  /* ---- Se lee el número de elementos pasando el parametro por referencia--------------------- */
  scanf("%d", &n);

  /* ---- Se reserva memoria para n enteros, inicializada en 0 --------------------------------- */
  ptr = (int*)calloc(n, sizeof(int));
  /* ---- Se verifica si la asignación fue exitosa --------------------------------------------- */
  if(ptr == NULL){
  /* ---- Si no lo fue, se muestra un mensaje de error y se termina el programa ---------------- */
    printf("Error! memory not allocated.");
    exit(0);
  }

  printf("Enter elements: ");

  /* ----Se realiza un bucle para recorrer la cantidad de elementos --------------------------- */
  for(i = 0; i < n; ++i){

  /* ---- Se lee el elemento en la posición i del arreglo ------------------------------------- */
    scanf("%d", ptr + i);
  /* ---- Se suma el elemento en la posición i del arreglo ----------------------------------- */
    sum += *(ptr + i);
  }

  /* ---- Se imprime la suma de los elementos del arreglo ------------------------------------ */
  printf("Sum = %d", sum);
  free(ptr);

  return 0;
}