# Actividad 1 — POSIX Semáforos (Productor/Consumidor)  
Pontificia Universidad Javeriana  
Profesor: John Jairo Corredor, PhD  
Autor: Thomas Leal Puerta, Carolina Ujueta Ricardo
Fecha: 13 Noviembre de 2025  

## Introducción
Esta actividad valida el patrón **Productor–Consumidor** empleando **semaforía POSIX con nombre** y **memoria compartida**.  
Se realizan dos pruebas: (A) el productor produce **solo 5 elementos** iniciales (llenado limitado del búfer) y (B) al iniciar el consumidor, los elementos se **consumen mientras** el productor **continúa enviando** hasta completar su secuencia.

## Requisitos
- Sistema operativo Linux con soporte POSIX.
- Compilador `gcc`.
- Cabeceras y librerías: `semaphore.h`, `fcntl.h`, `sys/mman.h`, `unistd.h`.

## Componentes
- `producer`: crea/abre semáforos y memoria compartida; inserta elementos en el búfer circular.
- `consumer`: abre los objetos creados por el productor; extrae elementos del búfer circular.

## Compilación y ejecución
# Compilar
- gcc producer.c -o producer
- gcc consumer.c -o consumer
