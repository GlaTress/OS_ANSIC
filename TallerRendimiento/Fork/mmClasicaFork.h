/************************************************************************************************************
 *                                   Pontificia Universidad Javeriana                                       *
 *                                                                                                          *
 * Autor:     Thomas Leal Puerta                                                                            *
 * Fecha:     14 de Noviembre de 2025                                                                       *
 * Materia:   Sistemas Operativos                                                                           *
 * Profesor:  John Jairo Corredor, PhD                                                                      *
 *  ENCABEZADO: funciones.h                                                                                 *
 *  Contiene las declaraciones de las funciones utilizadas en la multiplicación de matrices                 *
 *  usando paralelismo con procesos Fork.                                                                   *
 *                                                                                                          *
/************************************************************************************************************/

#ifndef MMCLASICAFORK_H
#define MMCLASICAFORK_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <time.h>

/* Funciones de medición de tiempo */
void InicioMuestra();
void FinMuestra();

/* Funciones para manejo de matrices */
void iniMatrix(double *mA, double *mB, int D);
void impMatrix(double *matrix, int D);
void multiMatrix(double *mA, double *mB, double *mC, int D, int filaI, int filaF);

#endif

