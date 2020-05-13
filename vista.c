#include "vista.h"

void printLista(void *head, tipoDeNodo tipo) {
  if(tipo == CALIFICACION) {
    Calificacion * current = (Calificacion *)head;
    while(current != NULL) {
      printNode(current, tipo);
      current = current->next;
    }
  } else {
    Nodo * current = (Nodo *)head;
    while(current != NULL) {
      printNode(current, tipo);
      current = current->next;
    }
  }
  printf("\n");
}

void printNode(void *nodo, tipoDeNodo tipo) {
  if(nodo == NULL) {
    char *str = tipo == USUARIO ? "e Usuario\0" : tipo == PELICULA ? "a Pelicula\0" : "a Calificacion\0";
    printf("No existe es%s\n", str);
  } else {
    if(tipo == CALIFICACION) {
      Calificacion * current = (Calificacion *)nodo;
      printf("Usuario: %s\tPelicula: %s\tRating: %f\n", current->usuario->nombre, current->pelicula->nombre, current->rating);
    } else {
      Nodo * current = (Nodo *)nodo;
      char *str = tipo == USUARIO ? "Usuario\0" : "Pelicula\0";
      printf("ID: %d\tNombre: %s\tTipo: %s\nFeatures:\n", current->id, current->nombre, str);
      for(int i = 0; i < N_FEATURES; i++) printf("\tFeature #%d: %f\n", i+1,current->feature_values[i]);
      printf("\n\n");
    }
  }
}
void printNodeName(Nodo *nodo, tipoDeNodo tipo) {
  if(nodo == NULL) {
    char *str = tipo == USUARIO ? "e Usuario\0" : tipo == PELICULA ? "a Pelicula\0" : "a Calificacion\0";
    printf("No existe es%s\n", str);
  } else {
    Nodo * current = (Nodo *)nodo;
    char *str = tipo == USUARIO ? "Usuario\0" : "Pelicula\0";
    printf("%s: %s\n", str, current->nombre);
  }
}
int askUserRating(char * titulo) {
  int rating;
  printf("Califica la pelicula \"%s\" con un numero entero del 0 al 10.\nSi no deseas calificar pon un numero afuera del rango.\nRating: ", titulo);
  scanf(" %d", &rating);
  return rating;
}
void printProgress(int length, int counter, int bar) {
  int percent = (int) (float)counter/(float)length*100;
  int writes = (int) (float)percent*(float)bar/100.0;
  for(int i = 0; i < writes; i++) {
    printf("#");
  }
  for(int i = writes; i < bar; i++) {
    printf("-");
  }
  printf(" [%d %%]\r", percent);
  fflush(stdout);
}

int askMovies(Nodo *peliculas[]) {
  int opcion;
  int valid = 1;;
  printf("Que pelicula se parece mas?\n");
  for(int j = 0; j < 2; j++) printf("\t%d --> %s\n", j, peliculas[j]->nombre);

  do {
    printf("Opcion: ");
    scanf("%d", &opcion);
    if(opcion > 1 || opcion < 0) {
      printf("Opcion invalida\n");
      valid = 0;
    }
  } while(!valid);
  return opcion;
}
