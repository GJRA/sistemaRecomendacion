#include "vista.h"

void printLista(void *head, tipoDeNodo tipo) {
  if(tipo == CALIFICACION) {
    Calificacion * current = (Calificacion *)head;
    while(current != NULL) {
      printf("Usuario: %s\tPelicula: %s\tRating: %d\n", current->usuario->nombre, current->pelicula->nombre, current->rating);
      current = current->next;
    }
  } else {
    Nodo * current = (Nodo *)head;
    while(current != NULL) {
      char *str = tipo == USUARIO ? "Usuario\0" : "Pelicula\0";
      printf("ID: %d\tNombre: %s\tTipo: %s\n", current->id, current->nombre, str);
      for(int i = 0; i < 17; i++) printf("%f\t", current->feature_values[i]);
      printf("\n");
      current = current->next;
    }
  }
  printf("\n");
}
