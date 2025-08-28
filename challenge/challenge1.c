/*************************************************************************************************************
*            Pontificia Universidad Javeriana                                                                *
*                                                                                                            *
* Autor:     Thomas Leal Puerta                                                                              *
* Fecha:     27 de Agosto, 2025                                                                              *
* Materia:   Sistemas Operativos                                                                             *
* Profesor:  John Jairo Corredor                                                                             *
* Objetivo:  Implementacion de Challenge1                                                                    *
*                                                                                                            *
**************************************************************************************************************
*                                                                                                            *
**************************************************************************************************************
*                                                                                                            *
* HOW TO USE                                                                                                 *
*                                                                                                            *
* HOW TO COMPILE TO PRODUCE EXECUTABLE PROGRAM:                                                              *
*   Linux/macOS:          gcc challenge1.c -o reto1                                                          *
*   Windows (MinGW):      gcc challenge1.c -o reto1.exe                                                      *
*                                                                                                            *
* HOW TO RUN THE PROGRAM:                                                                                    *
*   Linux/macOS:          ./reto1                                                                            *
*   Windows (CMD):        reto1.exe                                                                          *
*   Windows (PowerShell): .\reto1.exe                                                                        *
*************************************************************************************************************/

/************************************************* Headers **************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/************************************************************************************************************/
/*                                                                                                          */
/*  int main();                                                                                             */
/*                                                                                                          */
/*  Propósito: Demostrar asignación dinámica, copia e impresión de cadenas                                  */
/*             en C usando malloc, strcpy, printf y free.                                                   */
/*                                                                                                          */
/*  Retorno:   0 si finaliza correctamente.                                                                 */
/*                                                                                                          */
/************************************************************************************************************/
int main() {

    /* ---- Asigna el espacio de memoria suficiente para contener el literal para p y q---- */
    char *p = malloc(sizeof("Hello, I'm the best in Operating Systems!!!"));
    char *q = malloc(sizeof("Goodbye"));

    /* ---- Imprime la direccion de memoria de p------------------------------------------ */
    printf("Address of p = %p\n", p); 

    /* ---- Copia el contenido del literal a la cadena p---------------------------------- */
    strcpy(p, "Hello, I'm the best in Operating Systems!!!");
    /* ---- Imprime la cadena de caracteres de p------------------------------------------ */
    printf("%s\n", p);

    /* ---- Anuncia la copia a q---------------------------------------------------------- */
    printf("About to copy \"Goodbye\" to q\n"); 
    /* ---- Copia el contenido del literal a la cadena q---------------------------------- */
    strcpy(q, "Goodbye");    

    /* ---- Confirma que la copia se realizó---------------------------------------------- */
    printf("String copied\n");    

    /* ---- Imprime la cadena de caracteres de q------------------------------------------ */
    printf("%s\n", q);

    /* ---- Libera la memoria de p y de q------------------------------------------------- */
    free(p);
    free(q);

    return 0;
}
