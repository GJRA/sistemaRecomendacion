#include "controlador.h"

Nodo * agregarUsuario(char * nombre, Nodo * headUsuarios, Calificacion ** headCalificaciones, Nodo * headPeliculas) {
  Nodo * elemento = malloc(sizeof(Nodo));
  elemento->next = NULL;
  strcpy(elemento->nombre, nombre);
  elemento->id = headUsuarios == NULL ? 1 : getLastId(headUsuarios)+1;
  // for(int i = 0; i < 17; i++) elemento->feature_values[i] = i;//DEBUG
  int i = 0;
  while (i < 5) {
    Nodo *pelicula = randomMovie(headPeliculas);
    Calificacion * temp = malloc(sizeof(Calificacion));
    temp->pelicula = pelicula;
    temp->usuario = elemento;
    printNode(temp, CALIFICACION);
    if(getCalificacion(*headCalificaciones, temp) == NULL) {
      printNodeName(pelicula, PELICULA);
      int rating = askUserRating(pelicula->nombre);
      if(rating >= 0 && rating <= 10) {
        *headCalificaciones = calificaPelicula(elemento, pelicula, rating, *headCalificaciones);
        i++;
      }
    }
    free(temp);
  }
  return agregarALista(headUsuarios, elemento, USUARIO);
}
