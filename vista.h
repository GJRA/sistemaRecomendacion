#ifndef VISTA_H
#define VISTA_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "estructuras.h"
#include "modelo.h"

// -----------------------------
// Public interface
// -----------------------------

/* Function prototypes */
/**
 * El menu de nuestro sistema
 *
 *
 */
int menu();

/**
 * Imprime las sugerencias de amigos de un usuario
 *
 * @param nombre_usr nombre del usuario a buscar amigos
 */
void imprimirSugerenciaAmigos(char *nombre_usr);

void printNode(void *nodo, tipoDeNodo tipo);

/**
 * Imprime las sugerencias de peliculas de un usuario
 *
 * @param nombre_usr nombre del usuario a buscar peliculas
 */
void imprimirSugerenciaPeliculas(char *nombre_usr);

/**
 * Imprime peliculas parecidas de un titulo de pelicula
 *
 * @param nombre_peli nombre de la pelicula a buscar parecidas
 */
void imprimirPeliculasParecidas(char *nombre_peli);

/**
 * Imprime peliculas y el rating de un usuario
 *
 * @param nombre_usuario nombre del usuario a buscar peliculas y su rating
 */
void imprimirRatingPeliculasUsuario(char *nombre_usuario);

/**
 * Imprime los features de una pelicula y sus porcentajes
 *
 * @param nombre_pelicula nombre de la pelicula para su features
 */
void imprimirFeaturesPelicula(char *nombre_pelicula);

/**
 * Imprime los ratings de todos los usuarios por pelicula
 *
 * @param nombre_pelicula nombre de la pelicula para ver sus ratings
 */
void imprimirRatingPeliculasUsuario(char *nombre_pelicula);

/**
 * Imprime peliculas y el rating de un usuario
 *
 * @param nombre_usuario nombre del usuario a buscar peliculas y su rating
 */
void imprimirRatingPeliculasUsuario(char *nombre_usuario);

/**
 * Recorre e imprime una lista
 *
 * @param head apuntador al incio de la lista
 * @param tipo el tipo de los nodos de la lista
 */
void printLista(void *head, tipoDeNodo tipo);

/**
 * Imprime el nombre y tipo de un nodo
 *
 * @param nodo apuntador al nodo
 * @param tipo el tipo de los nodos de la lista
 */
void printNodeName(Nodo *nodo, tipoDeNodo tipo);

/**
 * Pide al usuario el rating de una película
 *
 * @param titulo titulo de la pelicula
 * @return el rating indicado
 */
int askUserRating(char * titulo);

/**
 * Imprime una barra de progreso (no se utiliza)
 *
 * @param length cantidad de información
 * @param counter en qué punto de la información vamos
 * @param bar longitud de la barra
 */
void printProgress(int length, int counter, int bar);

/**
 * Pide al usuario que escoja entre dos películas
 *
 * @param peliculas arreglo de películas
 * @return la posición de la película elegida
 */
int askMovies(Nodo *peliculas[]);
#endif
