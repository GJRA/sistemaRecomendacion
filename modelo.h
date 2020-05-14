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


/* Function prototypes */
/**
 * Genera y asigna un arreglo de N_FEATURES numeros flotantes aleatorios
 *
 * @param val arreglo donde guardará el arreglo generado
 */
void generarRand(float *val);
/**
 * Obtener datos de la matriz general
 *
 * @param nomFile es el nombre del csv donde se obtendran los datos
 * @param headUsuarios apuntador a la lista donde guardará los usuarios
 * @param headPeliculas apuntador a la lista donde guardará las peliculas
 * @param headCalificaciones apuntador a la lista donde guardará las calificaciones
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

/**
 * Agrega un elemento a una lista de Nodo
 *
 * @param head apuntador a la lista
 * @param elemento elemento que se desea agregar
 * @param tipo el tipo del nodo que se está agregando
 * @return apuntador al inicio de la lista
 */
Nodo * agregarALista(Nodo * head, Nodo * elemento, tipoDeNodo tipo);

/**
 * Agrega una nueva calificación a la lista de calificaciones
 *
 * @param head apuntador a la lista
 * @param elemento elemento que se desea agregar
 * @return apuntador al inicio de la lista
 */
Calificacion * agregarCalificacion(Calificacion * head, Calificacion * elemento);

/**
 * Obtiene el último elemento de una lista
 *
 * @param head apuntador a la lista
 * @param tipo el tipo de elementos que contiene la lista
 * @return apuntador al útlimo elemento de la lista
 */
void * getLast(void * head, tipoDeNodo tipo);

/**
 * Revisa si un elemento está en una lista de nodos
 *
 * @param head apuntador a la lista
 * @param elemento elemento que se desea buscar
 * @return 0 si no se encuentra y 1 si se encontró
 */
int checkInList(Nodo * head, Nodo * elemento);

/**
 * Busca en una lista un elemento, recibiendo su nombre
 *
 * @param head apuntador a la lista
 * @param nombre el nombre que se desea buscar
 * @return apuntador al elemento encontrado, NULL si no se encontró
 */
Nodo * searchInList(Nodo * head, char *nombre);

/**
 * Busca en la lista de calificaciones una calificación específica
 *
 * @param head apuntador a la lista
 * @param elemento el elemento calificación que se desea buscar
 * @return apuntador al elemento encontrado, NULL si no se encontró
 */
Calificacion * getCalificacion(Calificacion * head, Calificacion * elemento);

/**
 * Busca en una lista un elemento, recibiendo su id
 *
 * @param id el id que se desea buscar
 * @param head apuntador a la lista
 * @return apuntador al elemento obtenido
 */
Nodo * getById(int id, Nodo * head);

/**
 * Da el último ID de una lista de nodos
 *
 * @param head apuntador a la lista
 * @return el último ID de la lista
 */
int getLastId(Nodo *head);

/**
 * Devuelve una película aleatoria de la lista
 *
 * @param head apuntador a la lista
 * @return apuntador al elemento obtenido
 */
Nodo * randomMovie(Nodo *head);

/**
 * Devuelve la longitud de una lista
 *
 * @param head apuntador a la lista
 * @param tipo el tipo de los elementos de la lista
 * @return la longitud de la lista
 */
int getListLength(void *head, tipoDeNodo tipo);

/**
 * Devuelve el elemento en cierta posición de la lista
 *
 * @param head apuntador a la lista
 * @param pos la posición deseada
 * @param tipo el tipo de los elementos de la lista
 * @return apuntador al elemento en la posición deseada
 */
void * getByPosition(void * head, int pos, tipoDeNodo tipo);

/**
 * Crea una nueva Calificación entre un usuario y una película
 *
 * @param usuario el usuario que calificó
 * @param pelicula la película que se calificó
 * @param rating el rating que se le dio a la película
 * @param calificaciones la lista de calificaciones
 * @return apuntador a la lista de calificaciones
 */
Calificacion * calificaPelicula(Nodo * usuario, Nodo * pelicula, float rating, Calificacion * calificaciones);

/**
 * Devuelve el error rms del sistema
 *
 * @param headCalificacion la lista de calificaciones
 * @return el error rms
 */
float rms(Calificacion *headCalificacion);

/**
 * Calcula un arreglo que es el promedio de los features de una lista
 *
 * @param val el arreglo de features
 * @param head la lista
 */
void setGetPromedio(float *val, Nodo * head);

/**
 * Entrena un arreglo de features basándose en otro
 *
 * @param target el arreglo de features a entrenar
 * @param referencia el arreglo de features de referencia
 * @param learning_rate el learning rate a utilizar
 */
void entrenar(float *target, float *referencia, float rating, float learning_rate);

/**
 * Imprime un nodo a un archivo
 *
 * @param fp el archivo
 * @param nodo el nodo a imprimir
 * @param tipo el tipo del nodo a imprimir
 */
void printNodeFile(FILE *fp, void *nodo, tipoDeNodo tipo);

/**
 * Imprime una lista a un archivo
 *
 * @param fp el archivo
 * @param nodo el inicio de la lista a imprimir
 * @param tipo el tipo de los nodos a imprimir
 */
void printListaFile(FILE *fp, void *nodo, tipoDeNodo tipo);

/**
 * Imprime una matriz con usuarios, películas y calificaciones
 *
 * @param fp el archivo
 * @param usuarios la lista de usuarios
 * @param peliculas la lista de peliculas
 * @param calificaciones la lista de calificaciones
 * @param reporte si debe imprimir como reporte o no (decoraciones)
 */
void printMatrizFile(FILE *fp, Nodo *usuarios, Nodo *peliculas, Calificacion *calificaciones, int reporte);

/**
 * Revisa si un arreglo de nodos contiene el nodo
 *
 * @param lista el arreglo de nodos
 * @param nodo el nodo que se quiere revisar
 * @param length la longitud del arreglo
 * @return 0 si no lo contiene y 1 si si
 */
int contains(Nodo *lista[], Nodo *nodo, int length);

/**
 * Devuelve un arreglo de floats que son el promedio de los feature_values del arreglo
 *
 * @param val el arreglo en el que se escribiran los valores calculados
 * @param array el arreglo de películas
 * @param length la longitud del arreglo
 */
void promedioPeliculas(float *val, Nodo * array[], int length);

#endif
