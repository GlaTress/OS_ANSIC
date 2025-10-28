# Proyecto Laboratorios - Sistemas Operativos

## Descripción

Este proyecto contiene varios laboratorios desarrollados en C para la asignatura de Sistemas Operativos. Los laboratorios incluyen la creación y sincronización de hilos utilizando la biblioteca `pthread`, el manejo de mutexes y condiciones para la sincronización, y la manipulación de contadores compartidos. Todos los programas están diseñados para ser ejecutados en sistemas basados en Unix.

## Laboratorios

### lab01 - Hilos Independientes

**Objetivo**: Crear dos hilos independientes que imprimen un mensaje en consola.

- El programa crea dos hilos utilizando `pthread_create()`.
- Cada hilo ejecuta la función `print_message_function`, que recibe un mensaje y lo imprime.
- Al final, el hilo principal muestra los valores de retorno de los hilos.

### lab02 - Mutex para Sincronización

**Objetivo**: Crear 10 hilos que incrementan un contador compartido, utilizando un mutex para sincronización.

- Cada hilo ejecuta la función `thread_function`, que incrementa un contador global de forma segura.
- El acceso al contador está protegido con un mutex, evitando condiciones de carrera.
- El valor final del contador se muestra al final.

### lab03 - Condiciones y Mutex

**Objetivo**: Implementar dos hilos que interactúan entre sí utilizando variables de condición y mutex para sincronización.

- Los hilos incrementan un contador de manera sincronizada, utilizando un mutex y una variable de condición.
- El primer hilo espera que el contador alcance un valor antes de continuar, y el segundo hilo emite una señal cuando debe continuar.

### lab04 - Trabajos Concurrentes con Mutex

**Objetivo**: Crear varios hilos que realizan trabajos concurrentes y utilizan un mutex para sincronización en el acceso a una variable compartida.

- Cada hilo realiza un trabajo simulando un cálculo y utiliza un mutex para sincronizar el acceso a un contador compartido.
- Al final, se muestra el estado del contador después de que todos los hilos hayan finalizado.

### lab05 - Cálculo de Cuadrados de Números

**Objetivo**: Crear 20 hilos que calculan el cuadrado de números del 1 al 20 y suman los resultados.

- Cada hilo calcula el cuadrado de un número y lo suma al total acumulado.
- Se utiliza una variable global `acumulado`, y la suma es realizada sin sincronización, lo que puede llevar a resultados incorrectos si se ejecuta concurrentemente.

### lab06 - Cálculo de Cuadrados con Mutex

**Objetivo**: Crear 20 hilos para calcular el cuadrado de números del 1 al 20, utilizando un mutex para sincronizar el acceso a la variable global `acumulado`.

- Se asegura que el acceso al `acumulado` esté protegido mediante un mutex.
- Los resultados son sumados de manera segura, evitando condiciones de carrera.

### lab07 - Hilos y Condiciones

**Objetivo**: Crear dos hilos que interactúan entre sí utilizando mutex y condiciones.

- Un hilo reporta el valor de una variable, y el otro hilo asigna un nuevo valor y notifica al primer hilo utilizando una variable de condición.

### lab08 - Sincronización con Condiciones y Mutex

**Objetivo**: Mejorar la sincronización de hilos utilizando un mutex y una condición para asegurar que el segundo hilo espere hasta que el primer hilo haya sido notificado.

- El segundo hilo asigna un valor y notifica al primer hilo utilizando una condición. El primer hilo espera la notificación antes de imprimir el valor.

## Instrucciones de Uso

### Requisitos

- Un sistema basado en Linux o macOS con soporte para `pthread`.
- Tener instalado un compilador `gcc` o compatible.

### Compilación

Para compilar todos los laboratorios, simplemente ejecuta:

```
make

