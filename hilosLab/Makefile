##############################################################################################################
#            Pontificia Universidad Javeriana                                                                #
#                                                                                                            #
# Autor:     (Tu nombre o el de los autores)                                                                 #
# Fecha:     (Fecha de creación)                                                                             #
# Materia:   (Materia)                                                                                       #
# Profesor:  (Nombre del profesor)                                                                           #
# Objetivo:  Compilación de programas utilizando `gcc` y `pthread` para cada uno de los laboratorios.        #
##############################################################################################################
#                                                                                                            #
# HOW TO USE                                                                                                 #
#                                                                                                            #
# HOW TO COMPILE TO PRODUCE EXECUTABLE PROGRAM:                                                              #
#   make                                                                                                     #
#                                                                                                            #
# HOW TO RUN THE PROGRAM:                                                                                    #
#   ./lab1                                                                                                   #
#   ./lab2                                                                                                   #
#   (y así sucesivamente para los demás laboratorios)                                                        #
#                                                                                                            #
# CLEANING THE PROGRAM:                                                                                      #
#   make clean                                                                                               #
##############################################################################################################

# ************************************************* Variables *************************************************

CC = gcc  # Definición del compilador

# ************************************************* Reglas ****************************************************

# ---- Regla por defecto: compila todos los laboratorios listados ----
all: lab1 lab2 lab3 lab4 lab5 lab6 lab7 lab8 lab9

# ---- Compilación del laboratorio 1 ----
lab1: lab1.c
	$(CC) lab1.c -o lab1 -lpthread  # Compila lab1.c y genera lab1

# ---- Compilación del laboratorio 2 ----
lab2: lab2.c
	$(CC) lab2.c -o lab2 -lpthread  # Compila lab2.c y genera lab2

# ---- Compilación del laboratorio 3 ----
lab3: lab3.c
	$(CC) lab3.c -o lab3 -lpthread  # Compila lab3.c y genera lab3

# ---- Compilación del laboratorio 4 ----
lab4: lab4.c
	$(CC) lab4.c -o lab4 -lpthread  # Compila lab4.c y genera lab4

# ---- Compilación del laboratorio 5 ----
lab5: lab5.c
	$(CC) lab5.c -o lab5 -lpthread  # Compila lab5.c y genera lab5

# ---- Compilación del laboratorio 6 ----
lab6: lab6.c
	$(CC) lab6.c -o lab6 -lpthread  # Compila lab6.c y genera lab6

# ---- Compilación del laboratorio 7 ----
lab7: lab7.c
	$(CC) lab7.c -o lab7 -lpthread  # Compila lab7.c y genera lab7

# ---- Compilación del laboratorio 8 ----
lab8: lab8.c
	$(CC) lab8.c -o lab8 -lpthread  # Compila lab8.c y genera lab8

# ---- Compilación del laboratorio 9 ----
lab9: lab9.c
	$(CC) lab9.c -o lab9 -lpthread  # Compila lab9.c y genera lab9

# ---- Limpiar los ejecutables generados ----
clean:
	rm -f lab1 lab2 lab3 lab4 lab5 lab6 lab7 lab8 lab9  # Elimina los ejecutables
