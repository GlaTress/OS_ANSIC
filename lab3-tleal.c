/*************************************************************************************************************
*            Pontificia Universidad Javeriana                                                                *
*                                                                                                            *
* Autor:     Thomas Leal Puerta                                                                              *
* Fecha:     7 de Octubre, 2025                                                                              *
* Materia:   Sistemas Operativos                                                                             *
* Profesor:  John Jairo Corredor                                                                             *
* Objetivo:  Funcion Fork, creacion de procesos duplicidad de procesos y caos de creacion comunicaion entre  *
*            procesos usando PIPE                                                                            *
**************************************************************************************************************
*                                                                                                            *
* HOW TO USE                                                                                                 *
*                                                                                                            *
* HOW TO COMPILE TO PRODUCE EXECUTABLE PROGRAM:                                                              *
*   Linux/macOS:          gcc lab3_tleal.c -o lab3                                                           *
*   Windows (MinGW):      gcc lab3_tleal.c -o lab3.exe                                                       *
*                                                                                                            *
* HOW TO RUN THE PROGRAM:                                                                                    *
*   Linux/macOS:          ./lab3                                                                             *
*   Windows (CMD):        lab3.exe                                                                           *
*   Windows (PowerShell): .\lab3.exe                                                                         *
*************************************************************************************************************/

/************************************************* Headers **************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/************************************************************************************************************/
/*                                                                                                          */
/*  int main();                                                                                             */
/*                                                                                                          */
/*  Proposito: Crear un pipe y el proceso con fork() para que el PADRE escriba                              */
/*             un mensaje y el HIJO lo lea.                                                                 */
/*                                                                                                          */
/*  Retorno:   0 si el programa finaliza correctamente.                                                     */
/*                                                                                                          */
/************************************************************************************************************/
int main() {

    /* ---- Descriptores del pipe: [0] lectura, [1] escritura ---- */
    int pipefd[2];
    pid_t procesoHijoPID;

    /* ---- Creacion del pipe: canal de comunicacion padre->hijo ---- */
    if (pipe(pipefd) == -1) {
        perror("PIPE");
        exit(EXIT_FAILURE);
    }

    /* --- Creacion de proceso con fork() ---- */
    procesoHijoPID = fork();

    if (procesoHijoPID == -1) {
        perror("FORK");
        exit(EXIT_FAILURE);
    }

    /* ---- Proceso HIJO: cierra la escritura y se bloquea leyendo hasta que haya datos ---- */
    if (procesoHijoPID == 0) {
        /* ---- Cierra el extremo de escritura: solo leera ---- */
        close(pipefd[1]);

        /* ---- Bufer de recepcion ---- */
        char mensaje[100];

        /* ---- Lectura (puede bloquear si el padre aun no escribe) ---- */
        int lecBytes = read(pipefd[0], mensaje, sizeof(mensaje));
        if (lecBytes == -1) {
            perror("LECTURA");
            exit(EXIT_FAILURE);
        }

        /* ---- Al leer, el hijo ya tiene datos: se "estabiliza" la secuencia de impresion ---- */
        printf("\t ##==>Proceso HIJO recibe mensaje del PADRE %.*s \n", lecBytes, mensaje);

        /* ---- Cierre del extremo de lectura ---- */
        close(pipefd[0]);
    }
    /* ---- Proceso PADRE: cierra la lectura y escribe el mensaje al pipe ---- */
    else {
        /* ---- Cierra el extremo de lectura: solo escribira ---- */
        close(pipefd[0]);

        /* ---- Mensaje a enviar por el canal ---- */
        char mensaje[] = "HOLA SOY TU PADRE LUCK!!!";

        /* ---- Escritura al pipe (puede completar parcial, aqui el mensaje es pequeño) ---- */
        int escBytes = write(pipefd[1], mensaje, strlen(mensaje));
        if (escBytes == -1) {
            perror("ESCRITURA");
            exit(EXIT_FAILURE);
        }

        printf("\tPADRE: Envio mensaje al hijo.\n");

        /* ---- Cierre del extremo de escritura: notifica fin de datos al lector ---- */
        close(pipefd[1]);
    }

    /* ---- Mensaje final (puede aparecer antes o despues segun la planificacion) ---- */
    printf("\tFIN...\n");

    return 0;
}