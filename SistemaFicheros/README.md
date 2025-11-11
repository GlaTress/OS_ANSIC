# Laboratorios Ficheros — Sistemas Operativos  
Pontificia Universidad Javeriana  
Profesor: John Jairo Corredor, PhD  
Autor: Thomas Leal Puerta  
Fecha: 11 Noviembre de 2025  

## Introducción

Este conjunto de laboratorios introduce el uso de primitivas de sistema para **explorar directorios y ficheros** en C bajo Linux
Los ejercicios permiten:  
1) leer rutas desde entrada estándar,  
2) abrir y recorrer un directorio de forma segura,  
3) consultar datos POSIX de cada entrada,  
4) formatear un reporte mínimo (nombre, tiempo y tamaño).

## Requisitos

- Sistema operativo Linux.
- Compilador `gcc`.

## Laboratorios

### Lab01 – Listado básico de archivos y tamaños

**Objetivo:**  
Solicitar un directorio al usuario y **listar cada archivo regular** con su **nombre y tamaño (bytes)**.

**Conceptos aplicados:**  
- `opendir`, `readdir`, `closedir`  
- Construcción de rutas con concatenación segura  
- `stat` y macro `S_ISREG` para filtrar solo archivos regulares  

**Compilación y ejecución:**
make lab01
./lab01
luego escriba la ruta, por ejemplo:
Directorio

### Lab02 – Listado de archivos tamaños y tiempo

**Objetivo:**  
Solicitar un directorio al usuario y **listar cada archivo regular** con su **nombre, tamaño (bytes), permisos y tiempo de creacion**.

**Conceptos aplicados:**  
- `opendir`, `readdir`, `closedir`  
- Construcción de rutas con concatenación segura  
- `stat` y macro `S_ISREG` para filtrar solo archivos regulares  

**Compilación y ejecución:**
make lab02
./lab02
luego escriba la ruta, por ejemplo:
Directorio
