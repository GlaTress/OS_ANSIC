#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <math.h>

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

double funcion(int i) {
    int j, start = i * (i + 1) / 2, finish = start + i;
    double return_val = 0;
    for (j = start; j <= finish; j++)
        return_val += sin(j);
    return return_val;
}

int main(int argc, char* argv[]) {
    int i, N = 30000;                           /* valor por defecto */
    if (argc != 2) {
       printf("Error \n\t$.\ejecutable numHilos\n\n");
       exit(0);
    }
    int numHilos = (int) atoi(argv[1]);

    /* ---- Fijar el número de hilos deseado ---- */
    omp_set_num_threads((int)numHilos);

    /* ---- Acumulador de la sumatoria ---- */
    double sumatoria = 0.0;

    /* ======================== Inicio REGIÓN PARALELA por OpenMP ======================== */
    #pragma omp parallel
    {
        /* ---- Solo el hilo principal (master) informa configuración ---- */
        #pragma omp master
        {
            printf("Max hilos: %d || Hilos fijados: %d\n", omp_get_max_threads(), omp_get_num_threads());
        }

        /* ---- Todos los hilos participan en la suma (reducción por suma) ---- */
        #pragma omp for reduction(+:sumatoria) schedule(static)
        for (long i = 0; i < N; ++i) {
            sumatoria += funcion(i);
        }
    }
    /* ========================= Fin REGIÓN PARALELA por OpenMP ========================= */

    /* ---- Reporte final ---- */
    printf("Valor Sumatorio de función SENO: %.6f\n", sumatoria);
    return 0;
}
