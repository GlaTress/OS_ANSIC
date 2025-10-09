#############################################################################################################
#            Pontificia Universidad Javeriana                                                               #
#                                                                                                           #
# Autor:     Thomas Leal Puerta                                                                             #
# Fecha:     7 de Octubre, 2025                                                                             #
# Materia:   Sistemas Operativos                                                                            #
# Profesor:  John Jairo Corredor                                                                            #
# Objetivo:  Compilar los laboratorios lab1, lab2 y lab3 desde sus fuentes .c                               #
#                                                                                                           #
#############################################################################################################
#
# HOW TO USE
#
# Compilar todo:
#   make
#   make all
#
# Compilar uno específico (ej.: lab2):
#   make lab2
#
# Limpiar binarios:
#   make clean
#
#############################################################################################################

# ---------------------------- Variables del proyecto -------------------------------------------------------
# Ejecutables a generar
BINS := lab1 lab2 lab3

# Regla por defecto: compila todo
all: $(BINS)

# --------------------------------------- Reglas   ----------------------------------------------------------
# lab1 desde lab1_tleal.c (fork básico)
lab1: lab1_tleal.c
	gcc -o $@ $<

# lab2 desde lab2_tleal.c (fork + "caos de creación")
lab2: lab2_tleal.c
	gcc -o $@ $<

# lab3 desde lab3-tleal.c (fork + pipe)
lab3: lab3-tleal.c
	gcc -o $@ $<

# ---------------------------- Limpieza ---------------------------------------------------------------------
clean:
	rm -f $(BINS)
