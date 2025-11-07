##############################################################################################################
#            Pontificia Universidad Javeriana                                                                #
#                                                                                                            #
# Autor:     Thomas Leal Puerta                                                                              #
# Fecha:     6 de Noviembre de 2025                                                                          #
# Materia:   Sistemas Operativos                                                                             #
# Profesor:  John Jairo Corredor, PhD                                                                        #
# Objetivo:  Automatizar la compilación de los laboratorios OpenMP (lab01–lab05)                             #
#            utilizando GCC con las banderas -fopenmp y -lm.                                                 #
#                                                                                                            #
##############################################################################################################
#                                                                                                            #
# HOW TO USE                                                                                                 #
# ---------------------------------------------------------------------------------------------------------- #
# Compilar todos los laboratorios  : make                                                                    #
# Compilar un laboratorio específico: make lab05                                                             #
# Limpiar ejecutables generados    : make clean                                                              #
#                                                                                                            #
# Descripción:                                                                                                #
#   Este Makefile genera los binarios de los laboratorios OpenMP.                                            #
#   Cada regla compila un archivo fuente .c con soporte para multihilos (OpenMP).                            #
##############################################################################################################

# ************************************************* Variables *************************************************

GCC = gcc
FLAGS = -fopenmp -lm
PROGRAMAS = lab01 lab02 lab03 lab04 lab05

# ************************************************* Reglas ****************************************************

# ---- Regla por defecto: compila todos los programas listados ----
all: $(PROGRAMAS)

# ---- Compilación del laboratorio 1 ----
lab01: lab01.c
	$(GCC) $@.c -o $@ $(FLAGS)

# ---- Compilación del laboratorio 2 ----
lab02: lab02.c
	$(GCC) $@.c -o $@ $(FLAGS)

# ---- Compilación del laboratorio 3 ----
lab03: lab03.c
	$(GCC) $@.c -o $@ $(FLAGS)

# ---- Compilación del laboratorio 4 ----
lab04: lab04.c
	$(GCC) $@.c -o $@ $(FLAGS)

# ---- Compilación del laboratorio 5 ----
lab05: lab05.c
	$(GCC) $@.c -o $@ $(FLAGS)

# ---- Elimina todos los ejecutables generados ----
clean:
	rm -f $(PROGRAMAS)
