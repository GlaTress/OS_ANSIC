# Laboratorios OpenMP — Sistemas Operativos  
Pontificia Universidad Javeriana  
Profesor: John Jairo Corredor, PhD  
Autor: Thomas Leal Puerta  
Fecha: Noviembre de 2025  

## Introducción

Este conjunto de laboratorios introduce el uso de OpenMP (Open Multi-Processing), una API estándar para la programación paralela en sistemas de memoria compartida.  
Los ejercicios permiten comprender desde la creación de regiones paralelas básicas hasta el manejo de variables privadas y compartidas, la sincronización de hilos y el uso de la directiva `reduction`.

Cada laboratorio está escrito en lenguaje C y debe compilarse con la opción `-fopenmp` del compilador GCC.

## Requisitos

- Sistema operativo Linux o macOS con soporte para OpenMP.  
- Compilador GCC instalado (versión 9 o superior).  
- Librería matemática (`-lm`) disponible en el entorno.

## Laboratorios

### Lab01 – Introducción a OpenMP

**Objetivo:**  
Comprender la creación de regiones paralelas y la ejecución concurrente de múltiples hilos.

**Conceptos aplicados:**  
- Directiva `#pragma omp parallel`  
- Identificación de hilos (`omp_get_thread_num`)  
- Detección de número máximo de hilos (`omp_get_max_threads`)  

**Compilación y ejecución:**

gcc -fopenmp lab01.c -o lab01
./lab01

**Salida esperada:**

OpenMP ejecutando con 8 hilos
Hello world desde el thread 0
Hello world desde el thread 1
...


### Lab02 – Control de número de hilos

**Objetivo:**
Permitir que el usuario defina el número de hilos a usar en tiempo de ejecución mediante argumentos de línea de comandos.

**Conceptos aplicados:**

* `omp_set_num_threads(int n)`
* Control de argumentos CLI (`argc`, `argv`)
* Validación de entrada del usuario

**Compilación y ejecución:**

gcc -fopenmp lab02.c -o lab02
./lab02 numHilos

**Ejemplo:**

./lab02 4

**Salida esperada:**

OpenMP ejecutando en cores = 8 hilos disponibles
Hello world desde el thread 0
Hello world desde el thread 1
Hello world desde el thread 2
Hello world desde el thread 3

### Lab03 – Variables privadas

**Objetivo:**
Analizar el comportamiento de las variables privadas (`private`) y compartidas dentro de una región paralela.

**Conceptos aplicados:**

* Cláusula `private(var)`
* Independencia de variables entre hilos
* Variables compartidas fuera de la región paralela

**Compilación y ejecución:**

gcc -fopenmp lab03.c -o lab03
./lab03

**Salida esperada:**

a = 50 b = 1049 (Se espera a=50 b=1049)

---

### Lab04 – Variables privadas múltiples

**Objetivo:**
Extender el uso de la cláusula `private` a múltiples variables dentro de un bucle paralelo, mostrando cómo cada hilo mantiene sus propias copias.

**Conceptos aplicados:**

* `#pragma omp parallel for private(a,b,i)`
* Variables locales por hilo
* No interferencia de valores globales

**Compilación y ejecución:**

gcc -fopenmp lab04.c -o lab04
./lab04

**Salida esperada:**

a = 50 b = 1049 (Se espera a=50 b=1049)

---

### Lab05 – Reducción y medición de tiempo

**Objetivo:**
Implementar una sumatoria paralela controlando el número de hilos y tamaño de iteraciones desde CLI.
Medir el tiempo total de ejecución y comparar rendimiento con distintos números de hilos.

**Conceptos aplicados:**

* `#pragma omp parallel for reduction(+:var)`
* `schedule(static)` para balancear carga
* `omp_get_wtime()` para medir tiempo real
* Argumentos CLI: `numHilos` y `N`

**Compilación y ejecución:**

gcc -fopenmp lab05.c -o lab05 -lm
./lab05 numHilos N

**Ejemplo:**

./lab05 4 30000

---

## Compilación con Makefile

El archivo Makefile automatiza la compilación de todos los laboratorios.

**Comandos principales:**

make          # Compila todos los laboratorios
make lab03    # Compila un laboratorio específico
make clean    # Elimina ejecutables generados

Pontificia Universidad Javeriana — Departamento de Ingeniería de Sistemas
Curso: Sistemas Operativos
Profesor: PhD. John Jairo Corredor
Autor: Thomas Leal Puerta
Periodo: 2025-30
