#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "estructuras.h"
#include "modelo.h"
#include "vista.h"
// -----------------------------
// Public interface
// -----------------------------

/* Function prototypes */

Nodo * agregarUsuario(char * nombre, Nodo * headUsuarios, Calificacion ** headCalificaciones, Nodo * headPeliculas);

Nodo * recomendarAmigo(Nodo *headUsuarios,char *nombre);
Nodo * recomendarPelicula(Nodo *headPeliculas,Calificacion *headCalificacion,Nodo *headUsuarios, char *nombre);

void entrenarSistema(char *nomFile, Calificacion * calificaciones);

void printReporte(char *fileName, Nodo *usuarios, Nodo *peliculas, Calificacion *calificaciones);

void printCSV(char *fileName, Nodo *usuarios, Nodo *peliculas, Calificacion *calificaciones);
#endif
