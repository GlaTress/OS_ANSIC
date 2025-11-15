/************************************************************************************************************
 *                                   Pontificia Universidad Javeriana                                       *
 *                                                                                                          *
 * Autor:     Thomas Leal Puerta                                                                            *
 * Fecha:     14 de Noviembre de 2025                                                                       *
 * Materia:   Sistemas Operativos                                                                           *
 * Profesor:  John Jairo Corredor, PhD                                                                      *
 *                                                                                                          *
 *  DESCRIPCIÓN:                                                                                            *
 *  Archivo de encabezado que declara las funciones y estructuras necesarias para la                        *
 *  implementación del programa de multiplicación de matrices usando OpenMP.                                *
 *                                                                                                          *
 *  Incluye:                                                                                                *
 *  - Declaración de funciones de inicialización, impresión y multiplicación de matrices.                   *
 *  - Declaración de funciones para medición del tiempo de ejecución.                                       *
 *  - Inclusión de librerías estándar y OpenMP.                                                             *
 *                                                                                                          *
/************************************************************************************************************/

#ifndef MMCLASICAOPENMP_H
#define MMCLASICAOPENMP_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <omp.h>

/*------------------------------------------------------------------------------------------
 *  PROTOTIPOS DE FUNCIONES
 *-----------------------------------------------------------------------------------------*/
void InicioMuestra();
void FinMuestra();
void impMatrix(double *matrix, int D);
void iniMatrix(double *m1, double *m2, int D);
void multiMatrix(double *mA, double *mB, double *mC, int D);

#endif

