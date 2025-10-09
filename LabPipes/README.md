# Laboratorios de Sistemas Operativos — fork() y pipe()

**Autor:** Thomas Leal Puerta  
**Materia:** Sistemas Operativos  
**Profesor:** John Jairo Corredor  
**Fecha:** 7 de Octubre, 2025

Este repositorio contiene tres programas C, cada uno documentado con el formato institucional.

## Contenido

- `lab1_tleal.c` → ejecutable **lab1**  
  Demostración de **fork()** diferenciando ejecución de **padre** e **hijo** (Propósito en cabecera). :contentReference[oaicite:0]{index=0}
- `lab2_tleal.c` → ejecutable **lab2**  
  **fork()** con intercalación no determinista de impresiones (“**caos de creación**”) y su tendencia a estabilizar entre corridas. :contentReference[oaicite:1]{index=1}
- `lab3-tleal.c` → ejecutable **lab3**  
  **IPC con PIPE**: el **padre** escribe y el **hijo** lee tras `fork()`. :contentReference[oaicite:2]{index=2}

## Compilación

Con **Makefile**:

```bash
make        # compila lab1, lab2, lab3
make lab2   # compila solo lab2
make clean  # elimina binarios
