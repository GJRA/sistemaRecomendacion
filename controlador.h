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
/**
 * Agrega un nuevo usuario, pide que califique 5 películas, entrena el sistema
 *
 * @param nombre el nombre del nuevo usuario
 * @param headUsuarios la lista de usuarios
 * @param headCalificaciones la lista de calificaciones
 * @param headPeliculas la lista de peliculas
 * @return la lista de usuarios
 */
Nodo * agregarUsuario(char * nombre, Nodo * headUsuarios, Calificacion ** headCalificaciones, Nodo * headPeliculas);

/**
 * Da una recomendación de amigo
 *
 * @param headUsuarios la lista de usuarios
 * @param nombre el nombre del usuario al que se le dará la recomendación
 * @return el usuario recomendado
 */
Nodo * recomendarAmigo(Nodo *headUsuarios,char *nombre);

/**
 * Da una recomendación de película
 *
 * @param headPeliculas la lista de películas
 * @param headCalificacion la lista de calificaciones
 * @param headUsuarios la lista de usuarios
 * @param nombre el nombre del usuario al que se le dará la recomendación
 * @return la película recomendada
 */
Nodo * recomendarPelicula(Nodo *headPeliculas,Calificacion *headCalificacion,Nodo *headUsuarios, char *nombre);

/**
 * Entrena el sistema e imprimir un gráfico
 *
 * @param nomFile el nombre del archivo en el que escribir error vs. epoch
 * @param calificaciones la lista de calificaciones
 */
void entrenarSistema(char *nomFile, Calificacion * calificaciones);

/**
 * Imprime un reporte
 *
 * @param fileName el nombre del archivo en el que escribir el reporte
 * @param usuarios la lista de usuarios
 * @param peliculas la lista de películas
 * @param calificaciones la lista de calificaciones
 * @param calificaciones la lista de calificaciones
 */
void printReporte(char *fileName, Nodo *usuarios, Nodo *peliculas, Calificacion *calificaciones);

/**
 * Imprime una base de datos actualizada
 *
 * @param fileName el nombre del archivo en el que escribir la base de datos
 * @param usuarios la lista de usuarios
 * @param peliculas la lista de películas
 * @param calificaciones la lista de calificaciones
 * @param calificaciones la lista de calificaciones
 */
void printCSV(char *fileName, Nodo *usuarios, Nodo *peliculas, Calificacion *calificaciones);

/**
 * Obtiene tres películas parecidas
 *
 * @param headPeliculas la lista de películas
 * @param nombre el nombre de la película de cuál obtener las parecidas
 * @param peliculasParecidas el arreglo de películas parecidas
 */
void peliculasParecidas(Nodo *headPeliculas,char *nombre, Nodo *peliculasParecidas[]);

/**
 * Crea una nueva película
 *
 * @param nombre el nombre de la película que se creará
 * @param headPeliculas la lista de películas
 * @return la lista de películas
 */
Nodo * agregarPelicula(char * nombre, Nodo * headPeliculas);
#endif
