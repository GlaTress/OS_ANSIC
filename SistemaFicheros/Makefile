##############################################################################################################
#            Pontificia Universidad Javeriana                                                                #
#                                                                                                            #
# Autor:     Thomas Leal Puerta                                                                              #
# Fecha:     11 de Noviembre de 2025                                                                         #
# Materia:   Sistemas Operativos                                                                             #
# Profesor:  John Jairo Corredor, PhD                                                                        #
# Objetivo:  Automatizar la compilación de los laboratorios Ficheros (lab01–lab02)                           #
#            utilizando GCC                                                                                  #
#                                                                                                            #
##############################################################################################################
#                                                                                                            #
# HOW TO USE                                                                                                 #
# ---------------------------------------------------------------------------------------------------------- #
# Compilar todos los laboratorios  : make                                                                    #
# Compilar un laboratorio especifico: make lab01                                                             #
# Limpiar ejecutables generados    : make clean                                                              #
#                                                                                                            #
# Descripción:                                                                                               #
#   Este Makefile genera los binarios de los laboratorios de Ficheros.                                       #
#   Cada regla compila un archivo fuente .c con lectura de ficheros.                                         #
##############################################################################################################

# ************************************************* Variables *************************************************

GCC = gcc
FLAGS =
PROGRAMAS = Lab01 Lab02

# ************************************************* Reglas ****************************************************

# ---- Regla por defecto: compila todos los programas listados ----
all: $(PROGRAMAS)

# ---- Compilación del laboratorio 1 ----
lab01: lab01.c
        $(GCC) $@.c -o $@ $(FLAGS)

# ---- Compilación del laboratorio 2 ----
lab02: lab02.c
        $(GCC) $@.c -o $@ $(FLAGS)

# ---- Elimina todos los ejecutables generados ----
clean:
        rm -f $(PROGRAMAS)

