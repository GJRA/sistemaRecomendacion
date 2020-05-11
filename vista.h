#ifndef VISTA_H
#define VISTA_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "estructuras.h"

// -----------------------------
// Public interface
// -----------------------------

/* Function prototypes */
/**
 * El menu de nuestro sistema
 *
 *
 */
void menu();

/**
 * Imprime las sugerencias de amigos de un usuario
 *
 * @param nombre_usr nombre del usuario a buscar amigos
 */
void imprimirSugerenciaAmigos(char *nombre_usr);

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

void printLista(void *head, tipoDeNodo tipo);

#endif
