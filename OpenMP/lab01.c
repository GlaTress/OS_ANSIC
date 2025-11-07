/*      Autor: Thomas Leal Puerta
        Progrma:
        Fecha: 4 noviembre 2025
        Tema:
objetivo : introduccion en laboratorio openp
           clausulas y directivas para el programa
          gcc -fopenmp taller1.c -o taller1
*/

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
        printf("OpenMP ejecutando con %d hilos \n", omp_get_max_threads());
        #pragma omp parallel
        {
        printf("Hello world desde el thread %d\n", omp_get_thread_num());
        }
        return 0;
}
