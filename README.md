# Multiplicación de Matrices en C

## Descripción
Este proyecto implementa la multiplicación de matrices cuadradas en lenguaje C, aplicando una metodología modular para la organización del código.  
El programa reserva memoria dinámicamente para las matrices, las inicializa con valores numéricos, realiza la multiplicación y muestra los resultados.  

## Estructura del proyecto
```
├── Makefile        # Script de compilación
├── mod_tleal.c     # Programa principal (contiene main)
├── modulo.c        # Implementación de funciones auxiliares
└── modulo.h        # Definición de prototipos y cabeceras
```

## Funcionalidades principales
- Reserva de memoria dinámica para matrices NxN.  
- Inicialización automática de matrices A y B.  
- Multiplicación clásica de matrices almacenando el resultado en C.  
- Impresión de las matrices en consola.  
- Medición de tiempo de ejecución (inicio y fin).  

## Compilación
Este proyecto utiliza Makefile para simplificar la compilación.  
Para compilar, ejecutar en la terminal:

```bash
make mod_tleal
```

Esto generará un ejecutable:

```
mod_tleal
```
Se debe ejecutar 
```bash
./mod_tleal 3
```

## Archivos principales

### mod_tleal.c
- Contiene el `main()`.  
- Controla el flujo principal:  
  - Validación de argumentos.  
  - Reserva de memoria dinámica.  
  - Llamado a funciones de inicialización, impresión y multiplicación.  
  - Liberación de memoria.  

### modulo.c
Implementa funciones auxiliares:  
- `InicioMuestra()` - registra tiempo inicial.  
- `FinMuestra()` - registra tiempo final y calcula diferencia.  
- `iniMatriz()` - inicializa matrices A y B con valores numéricos.  
- `imprMatrices()` - imprime matrices (hasta cierto tamaño).  

### modulo.h
- Define los prototipos de las funciones de `modulo.c`.  
- Incluye las cabeceras necesarias (`<sys/time.h>`).    

## Autor
- Thomas Leal Puerta  
  Taller para la materia Sistemas Operativos  
  Tema: Multiplicación de Matrices  
