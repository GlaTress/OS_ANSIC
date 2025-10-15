/*************************************************************************************************************
*            Pontificia Universidad Javeriana                                                                *
*                                                                                                            *
* Autor:     Thomas Leal Puerta                                                                              *
* Fecha:     14 de octubre de 2025                                                                           *
* Materia:   Sistemas Operativos                                                                             *
* Profesor:  John Corredor Franco                                                                            *
* Objetivo:  Proceso CLIENTE para comunicación mediante FIFO (tubería con nombre) con un proceso SERVIDOR.   *
*                                                                                                            *
**************************************************************************************************************
*                                                                                                            *
* HOW TO USE                                                                                                 *
*                                                                                                            *
* HOW TO COMPILE TO PRODUCE EXECUTABLE PROGRAM:                                                              *
*   Linux/macOS:          gcc cliente.c -o cliente                                                           *
*   Windows (MinGW):      gcc cliente.c -o cliente.exe                                                       *
*                                                                                                            *
* HOW TO RUN THE PROGRAM:                                                                                    *
*   Linux/macOS:          ./cliente                                                                          *
*   Windows (CMD):        cliente.exe                                                                        *
*   Windows (PowerShell): .\cliente.exe                                                                      *
*                                                                                                            *
* NOTAS DE USO:                                                                                              *
*   - Asegúrese de ejecutar primero el SERVIDOR que crea/abre el FIFO compartido.                            *
*   - El nombre del FIFO está definido en la macro FIFO_FILE.                                                *
*                                                                                                            *
**************************************************************************************************************
 * Fecha: 14 de octubre de 2025
 * Autor:Thomas Leal Puerta
 * Materia: Sistemas Operativos
 * Tema: Comunicación entre procesos mediante FIFO (Named Pipes)
 * Objetivo: Implementar un proceso CLIENTE que se comunique con otro proceso SERVIDOR 
 *            a través de una tubería con nombre (FIFO). 
 * Descripción general:
 *  - El cliente envía cadenas de texto al servidor de manera continua hasta que se escriba "end".
 *  - Utiliza funciones del sistema para lectura y escritura a través del FIFO compartido.
 *  - La comunicación es bidireccional: el cliente envía una cadena y luego espera la respuesta.
 *  - Se emplea la función `open()` para abrir la tubería, `write()` para enviar datos 
 *    y `read()` para recibir la respuesta del servidor.
 *
 * Estructura del programa:
 *  - Definición de constantes y variables:
 *      - Se define el nombre del archivo FIFO en "/tmp/fifo_twoway".
 *      - Se crean variables para manejar la lectura y escritura.
 *  - Apertura del FIFO:
 *      - Se abre o crea la tubería en modo lectura/escritura (O_CREAT | O_RDWR).
 *  - Comunicación Cliente → Servidor:
 *      - Se solicita al usuario ingresar una cadena.
 *      - Se envía la cadena al servidor mediante `write()`.
 *      - Se recibe la respuesta mediante `read()` y se muestra por consola.
 *  - Condición de finalización:
 *      - Si el usuario ingresa la palabra “end”, el cliente envía este mensaje al servidor
 *        y finaliza el proceso cerrando el descriptor del FIFO.
 *
 * Consideraciones:
 *  - El cliente debe ejecutarse después de que el servidor haya creado el FIFO.
 *  - Si el servidor no está activo, la llamada a `open()` puede quedar bloqueada hasta que
 *    el FIFO sea abierto por el otro extremo.
*************************************************************************************************************/

/************************************************* Headers **************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

/* ---- Ruta del FIFO compartido entre cliente y servidor ---- */
#define FIFO_FILE "/tmp/fifo_twoway"

/************************************************************************************************************/
/*                                                                                                          */
/*  int main();                                                                                             */
/*                                                                                                          */
/*  Propósito: Ejecutar el bucle de envío/recepción del CLIENTE sobre una FIFO con nombre.                  */
/*             El usuario ingresa una cadena; el cliente la envía y espera la respuesta del SERVIDOR.       */
/*                                                                                                          */
/*  Parámetros: (ninguno)                                                                                   */
/*                                                                                                          */
/************************************************************************************************************/
int main() {

   /* ---- Descriptor del FIFO y variables de control de E/S ---- */
   int fd;                  /* descriptor de archivo para el FIFO */
   int end_process;         /* bandera para finalizar cuando sea "end" */
   int stringlen;           /* longitud de la cadena ingresada */
   int read_bytes;          /* bytes leídos desde el FIFO */
   char readbuf[80];        /* buffer para intercambio */
   char end_str[5];         /* palabra clave de finalización: "end" */

   /* ---- Mensaje inicial al usuario ---- */
   printf("FIFO_CLIENT: Send messages, infinitely, to end enter \"end\"\n");

   /* ---- Apertura/creación del FIFO para lectura y escritura ---- */
   /* ---- Nota: con O_CREAT, algunos sistemas requieren modo (no se modifica la lógica original). ---- */
   fd = open(FIFO_FILE, O_CREAT | O_RDWR);

   /* ---- Inicializa la palabra de término ---- */
   strcpy(end_str, "end");

   /* ---- Bucle principal de comunicación (envío -> espera respuesta) ---- */
   while (1) {

      /* ---- Solicita entrada al usuario ---- */
      printf("Enter string: ");
      fgets(readbuf, sizeof(readbuf), stdin);

      /* ---- Normaliza la cadena: elimina el salto de línea ---- */
      stringlen = (int)strlen(readbuf);
      readbuf[stringlen - 1] = '\0';

      /* ---- Compara contra la palabra de finalización ---- */
      end_process = strcmp(readbuf, end_str);

      /* ---- Si NO es "end": envía al servidor y espera respuesta ---- */
      if (end_process != 0) {

         /* ---- Envía la cadena por el FIFO ---- */
         write(fd, readbuf, strlen(readbuf));
         printf("FIFOCLIENT: Sent string: \"%s\" and string length is %d\n", readbuf, (int)strlen(readbuf));

         /* ---- Bloquea hasta recibir la respuesta del servidor ---- */
         read_bytes = read(fd, readbuf, sizeof(readbuf));
         readbuf[read_bytes] = '\0';

         /* ---- Muestra la respuesta del servidor ---- */
         printf("FIFOCLIENT: Received string: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));
      } 
      /* ---- Si es "end": envía, cierra FIFO y finaliza ---- */
      else {
         write(fd, readbuf, strlen(readbuf));
         printf("FIFOCLIENT: Sent string: \"%s\" and string length is %d\n", readbuf, (int)strlen(readbuf));

         /* ---- Cierra el descriptor del FIFO y rompe el bucle ---- */
         close(fd);
         break;
      }
   }

   /* ---- Fin normal del programa ---- */
   return 0;
}
