# Laboratorios de Sistemas Operativos — fork() y pipe()

**Autor:** Thomas Leal Puerta  
**Materia:** Sistemas Operativos  
**Profesor:** John Jairo Corredor  
**Fecha:** 7 de Octubre, 2025

Este repositorio contiene tres programas C, cada uno documentado.

## Contenido

- `lab1_tleal.c` → ejecutable **lab1**  
  Demostración de **fork()** diferenciando ejecución de **padre** e **hijo**
- `lab2_tleal.c` → ejecutable **lab2**  
  **fork()** con intercalación no determinista de impresiones (“**caos de creación**”) y su tendencia a estabilizar entre ejecuciones. 
- `lab3-tleal.c` → ejecutable **lab3**  
  **IPC con PIPE**: el **padre** escribe y el **hijo** lee tras `fork()`.

## Compilación

Con **Makefile**:

```bash
make        # compila lab1, lab2, lab3
make lab2   # compila solo lab2
make clean  # elimina binarios
