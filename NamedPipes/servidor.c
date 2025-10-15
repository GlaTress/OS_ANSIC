/*************************************************************************************************************
*            Pontificia Universidad Javeriana                                                                *
*                                                                                                            *
* Autor:     Thomas Leal Puerta                                                                              *
* Fecha:     14 de octubre de 2025                                                                           *
* Materia:   Sistemas Operativos                                                                             *
* Profesor:  John Corredor Franco                                                                            *
* Objetivo:  Implementar un proceso SERVIDOR que se comunique con un CLIENTE a través de una tubería         *
*             con nombre (FIFO) en el sistema operativo Linux.                                               *
*                                                                                                            *
**************************************************************************************************************
*                                                                                                            *
* HOW TO USE                                                                                                 *
*                                                                                                            *
* HOW TO COMPILE TO PRODUCE EXECUTABLE PROGRAM:                                                              *
*   Linux/macOS:          gcc servidor.c -o servidor                                                         *
*   Windows (MinGW):      gcc servidor.c -o servidor.exe                                                     *
*                                                                                                            *
* HOW TO RUN THE PROGRAM:                                                                                    *
*   Linux/macOS:          ./servidor                                                                         *
*   Windows (CMD):        servidor.exe                                                                       *
*   Windows (PowerShell): .\servidor.exe                                                                     *
**************************************************************************************************************
 * Fecha: 14 de octubre de 2025
 * Autor: Thomas Leal Puerta
 * Materia: Sistemas Operativos
 * Tema: Comunicación entre procesos mediante FIFO (Named Pipes)
 * Objetivo: Implementar un proceso SERVIDOR que se comunique con un CLIENTE a través 
 *            de una tubería con nombre (FIFO) en el sistema operativo Linux.
 *
 * Descripción general:
 *  - El servidor crea la tubería con nombre en "/tmp/fifo_twoway" utilizando `mkfifo()`.
 *  - Espera recibir cadenas enviadas por el cliente mediante `read()`.
 *  - Al recibir una cadena, verifica si es la palabra “end” para finalizar.
 *  - Si no lo es, invierte el contenido de la cadena y la envía de regreso al cliente 
 *    mediante `write()`.
 *  - Se utiliza la función auxiliar `reverse_string()` para invertir la cadena recibida.
 *
 * Estructura del programa:
 *  - Creación del FIFO:
 *      - Uso de `mkfifo()` para crear la tubería si no existe.
 *  - Apertura del FIFO:
 *      - Se abre en modo lectura/escritura (O_RDWR).
 *  - Ciclo de comunicación Servidor ↔ Cliente:
 *      - El servidor lee la cadena enviada por el cliente.
 *      - Si la cadena es distinta de “end”, la invierte y la reenvía.
 *      - Si la cadena es “end”, el servidor cierra el FIFO y termina la ejecución.
 *  - Función auxiliar `reverse_string()`:
 *      - Invierte los caracteres de una cadena de texto.
 *
 * Consideraciones:
 *  - El servidor debe ejecutarse antes que el cliente para que la tubería exista.
 *  - `sleep(2)` se usa para evitar que el servidor lea sus propios mensajes antes 
 *    de que el cliente los reciba.
 ************************************************************************************************************/

/************************************************* Headers **************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

/* ---- Ruta del FIFO compartido ---- */
#define FIFO_FILE "/tmp/fifo_twoway"

/* ---- Prototipo de función auxiliar ---- */
void reverse_string(char *);

/************************************************************************************************************/
/*                                                                                                          */
/*  int main();                                                                                             */
/*                                                                                                          */
/*  Propósito: Ejecutar el ciclo de servicio del SERVIDOR sobre una FIFO con nombre.                        */
/*             Lee cadenas del CLIENTE; si no es end, invierte la cadena y la reenvía.                      */
/*                                                                                                          */
/*  Parámetros: (ninguno)                                                                                   */
/*                                                                                                          */
/*  Retorno:   0 si finaliza correctamente.                                                                 */
/*                                                                                                          */
/************************************************************************************************************/
int main() {

   /* ---- Descriptores y variables de control ---- */
   int fd;                 /* descriptor del FIFO */
   char readbuf[80];       /* buffer de lectura/escritura */
   char end[10];           /* palabra de término: "end" */
   int to_end;             /* bandera de finalización */
   int read_bytes;         /* bytes leídos por iteración */

   /* ---- Creación del FIFO si no existe (permisos 0640) ---- */
   mkfifo(FIFO_FILE, S_IFIFO | 0640);

   /* ---- Palabra de finalización ---- */
   strcpy(end, "end");

   /* ---- Apertura del FIFO en lectura/escritura ---- */
   fd = open(FIFO_FILE, O_RDWR);

   /* ---- Ciclo principal de atención del servidor ---- */
   while (1) {

      /* ---- Lectura bloqueante desde el FIFO ---- */
      read_bytes = read(fd, readbuf, sizeof(readbuf));
      readbuf[read_bytes] = '\0';

      /* ---- Muestra lo recibido ---- */
      printf("FIFOSERVER: Received string: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));

      /* ---- Verifica si debe finalizar ("end") ---- */
      to_end = strcmp(readbuf, end);
      if (to_end == 0) {
         /* ---- Cierra FIFO y termina ---- */
         close(fd);
         break;
      }

      /* ---- Invierte la cadena recibida ---- */
      reverse_string(readbuf);

      /* ---- Muestra y reenvía la cadena invertida ---- */
      printf("FIFOSERVER: Sending Reversed String: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));
      write(fd, readbuf, strlen(readbuf));

      /* ---- Pausa breve para sincronizar lecturas/escrituras ---- */
      sleep(2);
   }

   /* ---- Fin normal ---- */
   return 0;
}

/************************************************************************************************************/
/*                                                                                                          */
/*  void reverse_string(char *str);                                                                         */
/*                                                                                                          */
/*  Propósito: Invertir in-place los caracteres de una cadena de texto.                                     */
/*                                                                                                          */
/*  Parámetros: str : puntero a la cadena terminada en '\0' a invertir.                                     */
/*                                                                                                          */
/*  Retorno:   (void)                                                                                       */
/*                                                                                                          */
/************************************************************************************************************/
void reverse_string(char *str) {

   /* ---- Índices y variable temporal ---- */
   int last, limit, first;
   char temp;

   /* ---- Calculo de límites ---- */
   last  = (int)strlen(str) - 1;
   limit = last / 2;
   first = 0;

   /* ---- Intercambia extremos avanzando hacia el centro ---- */
   while (first < last) {
      /* ---- Swap de caracteres en posiciones first y last ---- */
      temp        = str[first];
      str[first]  = str[last];
      str[last]   = temp;

      /* ---- Avance/retroceso de índices ---- */
      first++;
      last--;
   }

   /* ---- Retorno explícito (claridad) ---- */
   return;
}
