/*************************************************************************************************************
*  Programa:     Directorios y ficheros                                                                      *
*  autor:        Thomas Leal Puerta                                                                          *
*  Fecha:        11 de noviembre de 2025                                                                     *
*                                                                                                            *
*  Tema: Sistema de Ficheros                                                                                 *
* Descripcion: Programa en C que lea del teclado el nombre de un directorio y muestre en pantalla el nombre  *
*              fecha, permisos y el tamaño de los ficheros que contiene                                      *
*************************************************************************************************************/

/************************************************* Headers **************************************************/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

/************************************************************************************************************/
/*                                                                                                          *
/*  int main();                                                                                             *
/*                                                                                                          *
/*  Proposito:                                                                                              *
/*      Solicitar el nombre de un directorio, listar sus entradas y mostrar atributos con stat:           *
/*      modo, permisos basicos y filtrado de ficheros modificados en los ultimos 10 dias.                   *
/*                                                                                                          *
/*  Partes del metodo:                                                                                      *
/*      Parte 1: Declaraciones, lectura del nombre del directorio y apertura.                               *
/*      Parte 2: Recorrido de entradas, construccion de ruta, stat y reporte de atributos.               *
/*      Parte 3: Cierre del directorio y terminacion del programa.                                          *
/*                                                                                                          *
/*  Retorno:                                                                                                *
/*      -  0  si finaliza correctamente.                                                                    *
/*      - -1  si el directorio no existe o no puede abrirse.                                                *
/*                                                                                                          *
/************************************************************************************************************/
int main() {
    /* --- Parte 1 ---*/
    /* --- Codigo de retorno de stat (no critico) ---*/
    int er;
    /* --- Buffers para nombre de directorio y ruta de fichero ---*/
    char nomdir[100], nomfich[100];
    /* --- Estructura de atributos de archivo (stat) ---*/
    struct stat atr;
    /* --- Puntero al directorio ---*/
    DIR *d;
    /* --- Entrada de directorio leida por readdir ---*/
    struct dirent *rd1;
    /* --- Marca de tiempo actual ---*/
    time_t fecha;

    /* --- Solicitar el nombre del directorio ---*/
    printf("Nombre directorio:\n");
    /* --- Leer el nombre del directorio desde stdin ---*/
    fgets(nomdir, sizeof(nomdir), stdin);

    /* --- Quitar el salto de linea del nombre del directorio ---*/
    nomdir[strlen(nomdir) - 1] = '\0';
    /* --- Tomar tiempo actual (en segundos desde epoca) ---*/
    fecha = time(&fecha);

    /* --- Intentar abrir el directorio; validar error ---*/
    if ((d = opendir(nomdir)) == NULL) {
        /* --- No existe o no se puede abrir el directorio ---*/
        printf("No existe ese directorio\n");
        /* --- Finalizar con codigo de error ---*/
        return -1;
    } else {
        /* --- Parte 2 ---*/
        /* --- Recorrer todas las entradas del directorio ---*/
        while ((rd1 = readdir(d)) != NULL) {
            /* --- Omitir . y .. ---*/
            if ((strcmp(rd1->d_name, ".") != 0) && (strcmp(rd1->d_name, "..") != 0)) {
                /* --- Construir ruta: copiar directorio base ---*/
                strcpy(nomfich, nomdir);
                /* --- Annadir separador / ---*/
                strcat(nomfich, "/");
                /* --- Annadir nombre de la entrada ---*/
                strcat(nomfich, rd1->d_name);

                /* --- Imprimir ruta completa del fichero/entrada ---*/
                printf("Fichero: %s\n", nomfich);
                /* --- Obtener atributos con stat ---*/
                er = stat(nomfich, &atr);
                /* --- Imprimir modo (bits de permisos/tipo) en octal ---*/
                printf("Modo: %#o\n", atr.st_mode);

                /* --- Verificar permiso de lectura para propietario (0400) ---*/
                if ((atr.st_mode & 0400) != 0)
                    /* --- Tiene permiso R propietario ---*/
                    printf("Permiso R para propietario\n");
                else
                    /* --- No tiene permiso R propietario ---*/
                    printf("No permiso R para propietario\n");

                /* --- Si es directorio ---*/
                if (S_ISDIR(atr.st_mode))
                    printf("Es un directorio\n");
                /* --- Si es archivo regular ---*/
                if (S_ISREG(atr.st_mode)) {
                    /* --- Filtrar: modificados en los ultimos 10 dias ---*/
                    if ((fecha - 10 * 24 * 60 * 60) < atr.st_mtime) {
                        /* --- Imprimir nombre de fichero reciente ---*/
                        printf("FICHERO: %s\n", rd1->d_name);
                        /* --- Imprimir fecha de modificacion en formato legible ---*/
                        printf("Fecha de modificacion: %s", ctime(&atr.st_mtime));
                        /* --- Imprimir tiempo de modificacion en segundos ---*/
                        printf("Tiempo en segundos: %ld\n", atr.st_mtime);
                    }
                }
                /* --- Separador visual entre entradas ---*/
                printf("\n");
            }
        }
        /* --- Parte 3 ---*/
        /* --- Cerrar el directorio ---*/
        closedir(d);
    }

    /* --- Fin normal del programa ---*/
    return 0;
}
