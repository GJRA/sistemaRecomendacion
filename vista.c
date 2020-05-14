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
    } else {
      valid = 1;
    }
  } while(!valid);
  return opcion;
}

int menu(){
  int opc = 0;
  printf("\n\t\t\tSISTEMA DE RECOMENDACION NETFLIZ\t\t\t\n");
  // printf("Antes de usar este sistema se debe entrenar con un archivo csv\n");
  printf("Debes escribir el numero de la opcion que quieres\n");
  printf("\t1. Entrenar\n");
  printf("\t2. Imprimir sugerencia de amigos\n");
  printf("\t3. Imprimir sugerencia de peliculas para un usuario\n");
  printf("\t4. Imprimir rating de las peliculas de un usuario\n");
  printf("\t5. Imprimir los features de una pelicula\n");
  printf("\t6. Imprimir los features de un usuario\n");
  printf("\t7. Imprimir los ratings de todos los usuarios para una pelicula\n");
  printf("\t8. Generar Reporte\n");
  printf("\t9. Agregar nuevo usuario\n");
  printf("\t10. Agregar nueva pelicula\n");
  printf("\t11. Calificar pelicula\n");
  printf("\t12. Imprimir pelicula parecida\n");
  printf("\t13. Salir\n");
  printf("Opcion: ");
  scanf(" %d", &opc);
  return opc;
}

void imprimirCalificaciones(Calificacion * calificaciones, Nodo * nodo, tipoDeNodo tipo) {
  Calificacion * temp = malloc(sizeof(Calificacion));
  Calificacion * current = calificaciones;
  temp -> usuario = nodo;
  temp -> pelicula = nodo;
  char *str = tipo == USUARIO ? "Usuario:\0" : "Pelicula:\0";
  printf("%s: %s\n", str, nodo->nombre);
  while (current != NULL) {
    if(tipo == USUARIO && temp->usuario == current->usuario) printf("\tPelicula: %s\n\t\tRating: %d\n\n", current->pelicula->nombre, (int) round(current->rating*10));
    if(tipo == PELICULA && temp->pelicula == current->pelicula) printf("\tUsuario: %s\n\t\tRating: %d\n\n", current->usuario->nombre,(int) round(current->rating*10));
    current = current->next;
  }
}
