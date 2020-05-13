#ifndef MODELO_H
#define MODELO_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "estructuras.h"

// -----------------------------
// Public interface
// -----------------------------

void generarRand(float *val);
/* Function prototypes */
/**
 * Obtener datos de la matriz general
 *
 * @param nomFile es el nombre del csv donde se obtendran los datos
 */
void leerCSV(char *nomFile, Nodo **headUsuarios, Nodo **headPeliculas, Calificacion **headCalificacion);

/**
 * Crea la grafica Error vs Epochs
 *
 * @param nomFile es el nombre del csv donde se obtendran los datos
 * @param rms el valor del error rms
 * @param epoch el número de epoch
 */
void graficaErrorEpochs(char *nomFile, float rms, int epoch);
/**
 * Operacion producto punto entre 2 matrices
 *
 *
 * @param matriz matriz horizontal
 * @param matriz2 matriz vertical
 * @return el resultado producto punto
 */
float productoPunto(float *matriz, float *matriz2);

/**
 * Operacion resta entre 2 numeros
 *
 *
 * @param num1 Rating Esperado
 * @param num2 Rating Calculado
 * @return el resultado resta
 */
float error(float num1, float num2);

Nodo * agregarALista(Nodo * head, Nodo * elemento, tipoDeNodo tipo);

Calificacion * agregarCalificacion(Calificacion * head, Calificacion * elemento);

void * getLast(void * head, tipoDeNodo tipo);

int checkInList(Nodo * head, Nodo * elemento);

Nodo * searchInList(Nodo * head, char *nombre);

Calificacion * getCalificacion(Calificacion * head, Calificacion * elemento);

Nodo * getById(int id, Nodo * head);

int getLastId(Nodo *head);

Nodo * randomMovie(Nodo *head);

int getListLength(void *head, tipoDeNodo tipo);

void * getByPosition(void * head, int pos, tipoDeNodo tipo);

Calificacion * calificaPelicula(Nodo * usuario, Nodo * pelicula, float rating, Calificacion * calificaciones);

float rms(Calificacion *headCalificacion);

void setGetPromedio(float *val, Nodo * head);

void entrenar(float *target, float *referencia, float rating, float learning_rate);


void printNodeFile(FILE *fp, void *nodo, tipoDeNodo tipo);

void printListaFile(FILE *fp, void *nodo, tipoDeNodo tipo);

void printMatrizFile(FILE *fp, Nodo *usuarios, Nodo *peliculas, Calificacion *calificaciones, int reporte);

#endif
