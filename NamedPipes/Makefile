##############################################################################################################
#            Pontificia Universidad Javeriana                                                                #
#                                                                                                            #
# Autor:     Thomas Leal Puerta                                                                              #
# Fecha:     14 de octubre, 2025                                                                             #
# Materia:   Sistemas Operativos                                                                             #
# Profesor:  John Corredor Franco                                                                            #
# Objetivo:  Makefile para compilar los procesos cliente y servidor que se comunican mediante FIFO.          #
#                                                                                                            #
##############################################################################################################
#                                                                                                            #
# HOW TO USE                                                                                                 #
#                                                                                                            #
# HOW TO COMPILE TO PRODUCE EXECUTABLE PROGRAM:                                                              #
#   Linux/macOS/MinGW:    make                                                                               #
#   Solo cliente:         make cliente                                                                       #
#   Solo servidor:        make servidor                                                                      #
#                                                                                                            #
# HOW TO RUN THE PROGRAM:                                                                                    #
#   Servidor:             ./servidor                                                                         #
#   Cliente:              ./cliente                                                                          #
#                                                                                                            #
# LIMPIEZA:                                                                                                  #
#   Limpiar binarios:     make clean                                                                         #
##############################################################################################################

# ************************************************* Variables *************************************************

# ---- Conjunto de ejecutables a construir ----
pep = cliente servidor

# ************************************************* Reglas ****************************************************

# ---- Regla por defecto: compila todos los ejecutables listados en $(pep) ----
all: $(pep)

# ---- Cliente: compila cliente.c en el ejecutable 'cliente' ----
cliente: cliente.c
	gcc -o $@ $<

# ---- Servidor: compila servidor.c en el ejecutable 'servidor' ----
servidor: servidor.c
	gcc -o $@ $<

# ---- Limpieza de ejecutables generados ----
clean:
	rm -f $(pep)
