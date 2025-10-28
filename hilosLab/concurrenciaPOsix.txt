/*********************************************************************************************
 * Pontificia Universidad Javeriana
 *
 * Materia Sistemas Operativos
 * Docente: J. Corredor, PhD
 * Fecha: 27/10/2025
 * Tema: Posix para la creación de hilos concurrentes:
 *
 * Descripción:
 * Este programa busca encontrar el valor máximo de un vector de enteros. Para ello, se utiliza
 * la librería POSIX para crear hilos concurrentes que procesan fragmentos del vector en paralelo.
 * Los hilos realizan una búsqueda parcial del máximo y el hilo principal combina los resultados
 * para determinar el valor máximo final.
 *********************************************************************************************/

/************************************************* Headers **************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/************************************************************************************************************/
/*                                                                                                          */
/*  Estructura de argumentos para los hilos.                                                                */
/*  La estructura contiene los índices de inicio y fin para que cada hilo procese un fragmento del vector.  */
/*  Además, tiene un campo para almacenar el máximo parcial encontrado por el hilo.                         */
/*                                                                                                          */
/*  Parametros: inicio  : índice de inicio del fragmento de datos a procesar.                               */
/*             fin     : índice final del fragmento.                                                        */
/*             vector  : puntero al vector de enteros a analizar.                                           */
/*             maxparcial : valor máximo encontrado por el hilo en su fragmento.                            */
/*                                                                                                          */
/************************************************************************************************************/
struct argHilos {
    int inicio;        // Índice de inicio del fragmento
    int fin;           // Índice final del fragmento
    int *vector;       // Puntero al vector de enteros
    int maxparcial;    // Máximo parcial encontrado por el hilo
};

typedef struct argHilos param_H;  // Alias para facilitar el uso de la estructura

/**************************************************************************************************************/
/*                                                                                                            */
/*  void *buscarMax(void *parametro);                                                                         */
/*                                                                                                            */
/*  Propósito: Cada hilo ejecuta esta función para buscar el máximo en su fragmento del vector.               */
/*  Los resultados se almacenan en el campo `maxparcial` de la estructura de parámetros.                      */
/*                                                                                                            */
/*  Parámetros: parametro : puntero a la estructura que contiene los índices, vector y la variable de salida. */
/*                                                                                                            */
/*  Retorno:   NULL (hilo termina su ejecución con pthread_exit).                                             */
/*                                                                                                            */
/**************************************************************************************************************/
void *buscarMax(void *parametro) {
    param_H *argumentos = (param_H *)parametro;  // Casting de puntero a la estructura de argumentos

    // Inicializa el máximo parcial con el primer valor del fragmento
    argumentos->maxparcial = argumentos->vector[argumentos->inicio];
    
    // Recorre el fragmento asignado al hilo buscando el valor máximo
    for(int i = argumentos->inicio; i < argumentos->fin; i++) {
        if(argumentos->vector[i] > argumentos->maxparcial) {
            argumentos->maxparcial = argumentos->vector[i];  // Actualiza el máximo parcial
        }
    }
    
    pthread_exit(0);  // Termina el hilo
    return NULL;
}

/************************************************************************************************************/
/*                                                                                                          */
/*  int maximoValor(int *vector, int n, int nhilos);                                                        */
/*                                                                                                          */
/*  Propósito: Divide el vector entre varios hilos y recoge los máximos parciales para obtener el máximo.   */
/*                                                                                                          */
/*  Parámetros: vector : puntero al vector de enteros a analizar.                                           */
/*             n       : tamaño del vector.                                                                 */
/*             nhilos  : número de hilos a crear.                                                           */
/*                                                                                                          */
/*  Retorno:   El valor máximo encontrado.                                                                  */
/*                                                                                                          */
/************************************************************************************************************/
int maximoValor(int *vector, int n, int nhilos) {
    pthread_t hilos[nhilos];  // Array para almacenar los identificadores de los hilos
    param_H parametros[nhilos];  // Array de estructuras para pasar parámetros a los hilos

    // Calcula el tamaño del fragmento para cada hilo
    int fragmento = n / nhilos;

    // Crea los hilos, cada uno con su fragmento
    for(int i = 0; i < nhilos; i++) {
        parametros[i].inicio = i * fragmento;
        parametros[i].fin = (i + 1) * fragmento;
        
        // Asegura que el último hilo procese hasta el final del vector
        if (i == nhilos - 1) {
            parametros[i].fin = n;
        }
        
        parametros[i].vector = vector;  // Asigna el vector a la estructura

        // Crea el hilo
        pthread_create(&hilos[i], NULL, buscarMax, (void *)&parametros[i]);
    }

    // Espera a que todos los hilos terminen
    for(int i = 0; i < nhilos; i++) {
        pthread_join(hilos[i], NULL);
    }

    // Recolecta el máximo parcial de cada hilo
    int max = parametros[0].maxparcial;
    for(int i = 1; i < nhilos; i++) {
        if(parametros[i].maxparcial > max) {
            max = parametros[i].maxparcial;  // Actualiza el máximo total
        }
    }

    return max;
}

/************************************************************************************************************/
/*                                                                                                          */
/*  int main(int argc, char *argv[]);                                                                       */
/*                                                                                                          */
/*  Propósito: Leer un vector desde un archivo, dividirlo y usar hilos para encontrar el máximo.            */
/*                                                                                                          */
/*  Parámetros: argc/argv : el archivo que contiene el vector y el número de hilos a utilizar.              */
/*                                                                                                          */
/*  Retorno:   0 en finalización correcta.                                                                  */
/*                                                                                                          */
/************************************************************************************************************/
int main(int argc, char *argv[]) {
    FILE *fichero;  // Puntero al archivo
    int n, nhilos, i;  // Variables para el tamaño del vector y el número de hilos
    int *vec;  // Puntero al vector
    int ret, maximo;

    // Verificación de los argumentos de entrada
    if (argc != 3) {
        fprintf(stderr, "Error en número de argumentos \n");
        exit(-1);
    }

    // Abrir el archivo de entrada
    fichero = fopen(argv[1], "r");
    if (fichero == NULL) {
        perror("No se puede abrir fichero");
        exit(-2);
    }

    // Leer el tamaño del vector desde el archivo
    ret = fscanf(fichero, "%d", &n);
    if (ret != 1) {
        fprintf(stderr, "No se puede leer tamaño\n");
        exit(-3);
    }

    nhilos = atoi(argv[2]);  // Número de hilos a utilizar
    vec = malloc(sizeof(int) * n);  // Asignación de memoria para el vector

    // Leer los elementos del vector desde el archivo
    for (i = 0; i != n; ++i) {
        ret = fscanf(fichero, "%d", &vec[i]);
        if (ret != 1) {
            fprintf(stderr, "No se puede leer elemento nro %d\n", i);
            fclose(fichero);
            free(vec);
            exit(-4);
        }
    }

    // Encontrar el valor máximo utilizando los hilos
    maximo = maximoValor(vec, n, nhilos);
    printf("Máximo: %d\n", maximo);

    // Cerrar el archivo y liberar memoria
    fclose(fichero);
    free(vec);

    return 0;
}


