/************************************************************************************************************
 *                                   Pontificia Universidad Javeriana                                       *
 *                                                                                                          *
 * Autor:     Thomas Leal Puerta                                                                            *
 * Fecha:     14 de Noviembre de 2025                                                                       *
 * Materia:   Sistemas Operativos                                                                           *
 * Profesor:  John Jairo Corredor, PhD                                                                      *
 *                                                                                                          *
 *  DESCRIPCIÓN:                                                                                            *
 *  Declaraciones, estructuras y prototipos utilizados en la implementación del algoritmo                   *
 *  de multiplicación de matrices transpuestas con paralelismo OpenMP.                                      *
/************************************************************************************************************/

#ifndef MM_FILAS_OPENMP_H
#define MM_FILAS_OPENMP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <omp.h>

/* Prototipos de funciones */
void InicioMuestra();
void FinMuestra();
void iniMatrix(double *m1, double *m2, int D);
void impMatrix(double *matrix, int D, int t);
void multiMatrixTrans(double *mA, double *mB, double *mC, int D);

#endif

