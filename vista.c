#include "vista.h"

void printReporte(char *fileName, Nodo *usuarios, Nodo *peliculas, Calificacion *calificaciones) {
  FILE *fp;
  fp=fopen(fileName,"w+");
  fprintf(fp, "REPORTE DEL PROGRAMA\n\n");
  printListaFile(fp, usuarios, USUARIO);
  fprintf(fp, "\n");
  printListaFile(fp, peliculas, PELICULA);
  fprintf(fp, "\n");
  printMatrizFile(fp, usuarios, peliculas, calificaciones);
  fclose(fp);
}

void printMatrizFile(FILE *fp, Nodo *usuarios, Nodo *peliculas, Calificacion *calificaciones) {
  int usersLength = getListLength(usuarios, USUARIO);
  int quantity = (usersLength+1)*5+2;
  for (int i = 0; i < quantity; i++) fprintf(fp, "=");
  fprintf(fp, "\n");
  fprintf(fp, "| ID |");
  Nodo *current = usuarios;
  while (current != NULL) {
    fprintf(fp, "| %2d ", current->id);
    current = current->next;
  }
  fprintf(fp, "|\n");
  for (int i = 0; i < quantity; i++) fprintf(fp, "=");
  fprintf(fp, "\n");
  current = peliculas;
  while (current != NULL) {
    fprintf(fp, "| %2d |", current->id);
    Nodo *currentUser = usuarios;
    while(currentUser != NULL) {
      Calificacion * elemento = malloc(sizeof(Calificacion));
      elemento->usuario = currentUser;
      elemento->pelicula = current;
      Calificacion *calif = getCalificacion(calificaciones, elemento);
      int rating = calif == NULL ? -1 : (calif->rating)*10;
      fprintf(fp, "| %2d ", rating);
      currentUser = currentUser->next;
      free(elemento);
    }
    fprintf(fp, "|\n");
    for (int i = 0; i < quantity; i++) fprintf(fp, "-");
    fprintf(fp, "\n");
    current = current->next;
  }
}

void printListaFile(FILE *fp, void *head, tipoDeNodo tipo) {
  if (tipo == CALIFICACION) {

  } else {
    Nodo * current = (Nodo *)head;
    char *str = tipo == USUARIO ? "Usuarios\0" : "Peliculas\0";
    fprintf(fp, "%s:\n", str);
    while(current != NULL) {
      printNodeFile(fp, current, tipo);
      current = current->next;
    }
  }
}

void printNodeFile(FILE *fp, void *nodo, tipoDeNodo tipo) {
  if(tipo == CALIFICACION) {
    Calificacion * current = (Calificacion *)nodo;
    fprintf(fp, "%f\t", current->rating);
  } else {
      Nodo * current = (Nodo *)nodo;
      if(current->nombre[strlen(current->nombre)-1] == '\n') current->nombre[strlen(current->nombre)-1] = '\0';
      fprintf(fp, "\n");
      fprintf(fp, "\t\t\t\t    ID: %d\t\tNombre: %s\n", current->id, current->nombre);
      for(int i = 0; i < 97; i++) fprintf(fp, "=");
      fprintf(fp, "\n");
      fprintf(fp, "|\t\t\t\t\t    Features\t\t\t\t\t\t|\n");
      for(int i = 0; i < 97; i++) fprintf(fp, "=");
      fprintf(fp, "\n");
      for(int i = 0; i < N_FEATURES/4*5; i++) {
        if(i % 4 == 0 && i != 0) {
            fprintf(fp, "|\n");
            for(int i = 0; i < 97; i++) fprintf(fp, "-");
            fprintf(fp, "\n");
        }
        if(i < N_FEATURES) {
          fprintf(fp, "|\t%f\t", current->feature_values[i]);
        } else {
          fprintf(fp, "|\t\t\t");
        }
      }
      fprintf(fp, "|\n");
      for(int i = 0; i < 97; i++) fprintf(fp, "=");
      fprintf(fp, "\n\n");
  }
}

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
      printf("ID: %d\tNombre: %s\tTipo: %s\n", current->id, current->nombre, str);
      for(int i = 0; i < N_FEATURES; i++) printf("%f,", current->feature_values[i]);
      printf("\n");
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

void printFeature(char *nombre,Nodo *headNodo){
  char nombreFeatures[17][15] = {"Terror/Suspenso","Accion","Comedia","Dramatica",
  "Musicales","Ciencia Ficcion","Guerra","Crimen","Infantil","Romance",
  "Animada","Fantasia","Extranjera","Larga","Culto","Documental","Basada en Hechos"
  };
  Nodo *nodo = searchInList(headNodo, nombre);
  printf("Features de %s\n",nodo->nombre);
  for(int i=0;i<17;i++){
    printf("%s -- > %f\n",nombreFeatures[i],nodo->feature_values[i]);
  }
}

int menu(){
  int opc = 0;
  printf("\n\t\t\tSISTEMA DE RECOMENDACION NETFLIZ\t\t\t\n");
  printf("Antes de usar este sistema se debe entrenar con un archivo csv\n");
  printf("Debes escribir el numero de la opcion que quieres\n");
  printf("\t1. Entrenar\n");
  printf("\t2. Imprimir sugerencia de amigos\n");
  printf("\t3. Imprimir sugerencia de peliculas para un usuario\n");
  printf("\t4. Imprimir rating de las peliculas de un usuario\n");
  printf("\t5. Imprimir los features de un pelicula\n");
  printf("\t6. Imprimir los features de un usuario\n");
  printf("\t7. Imprimir los ratings de todos los usuarios para una pelicula\n");
  printf("\t8. Generar Reporte\n");
  printf("\t9. Agregar nuevo usuario\n");
  printf("\t10. Agregar nueva pelicula\n");
  printf("\t11. Calificar pelicula\n");
  printf("\t12. Salir\n");
  scanf(" %d", &opc);
  return opc;
}
