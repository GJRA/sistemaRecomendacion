#include "modelo.h"
/* Private types */
void generarRand(float *val, int length){
    //float valores[17];
    for(int i = 0; i < length; i++){
        val[i] = (float)rand()/(float)(RAND_MAX/1);
    }
}


void leerCSV(char *nomFile, Nodo **headUsuarios, Nodo **headPeliculas, Calificacion **headCalificacion){
	FILE *file;
	file = fopen(nomFile, "r");
  Nodo *elemPu = NULL;
  Nodo *elemQi = NULL;

	int i = 0;
    char line[4098];
    while (fgets(line, 4098, file))
    {
        int pos = 0;
        int j = 0;
        const char* tmp = strdup(line);
        char delimitador[] = ",";
        char *token = strtok(tmp, delimitador);
        if(token != NULL){
            while(token != NULL){
                if(i==0){
                    if(j!=0){
                        elemPu = malloc (sizeof (Nodo));
                        elemPu -> next = NULL;
                        if(elemPu == NULL) printf("ERROR crear Usuario\n");
                        elemPu -> id = j-1;
                        //int len = strlen(token);
                        //if(token[len-1] == '\n') token[len-1] = 0;
                        strcpy(elemPu -> nombre,token);
                        generarRand(elemPu->feature_values, 17);
                        //Primer renglon con usuarios
                        // printf("Nombres: ");
                        // printf("%s\t",token);
                        *headUsuarios = agregarALista(*headUsuarios, elemPu, USUARIO);
                    }
                }else{
                    if(j == 0){
                        elemQi = malloc (sizeof (Nodo));
                        if(elemQi == NULL) printf("ERROR crear Pelicula\n");
                        elemQi -> id = i-1;
                        elemQi->next = NULL;
                        strcpy(elemQi -> nombre,token);
                        generarRand(elemQi->feature_values, 17);
                        // printf("Peli %s\t",token );
                        *headPeliculas = agregarALista(*headPeliculas, elemQi, PELICULA);
                    } else {
                      Nodo *temp = NULL;
                      temp = getById(pos, *headUsuarios);
                      if(atoi(token)>=0 && temp != NULL) {
                        Calificacion *elemCali = malloc (sizeof (Calificacion));
                        if(elemCali == NULL) printf("ERROR crear calificacion\n");
                        elemCali -> usuario = temp;
                        elemCali -> pelicula = elemQi;
                        elemCali -> rating = atoi(token);
                        elemCali->next = NULL;
                        // printf("%s\t",token);
                        *headCalificacion = agregarCalificacion(*headCalificacion, elemCali);
                      }
                      pos++;
                    //   Nodo * temp = NULL;
                    //   do {
                    //     if(atoi(token)>=0 && temp != NULL){
                    //         Calificacion *elemCali = malloc (sizeof (Calificacion));
                    //         if(elemCali == NULL) printf("ERROR crear calificacion\n");
                    //         elemCali -> usuario = temp;
                    //         elemCali -> pelicula = elemQi;
                    //         elemCali -> rating = atoi(token);
                    //         // printf("%s\t",token);
                    //         *headCalificacion = agregarCalificacion(*headCalificacion, elemCali);
                    //     }
                    //     pos++;
                    //   } while(temp != NULL);
                    }

                }
                j++;
                token = strtok(NULL, delimitador);
            }
        }
        free(tmp);
        i++;
    }
}

Nodo * getById(int id, Nodo * head) {
    Nodo *current = head;
    while(current != NULL) {
      if(current->id == id) break;
      current = current->next;
    }
    return current;
}

Nodo * agregarALista(Nodo * head, Nodo * elemento, tipoDeNodo tipo) {
  Nodo * current = head;
  if(current == NULL) {
    current = elemento;
    return current;
  }
  if(!checkInList(head, elemento)) {
    current = (Nodo *)getLast(head, tipo);
    current->next = elemento;
  } else {
    char *str = (tipo ==  USUARIO ? "El usuario\0" : "La pelicula\0");
    printf("%s %s ya existe!!\n", str, elemento->nombre);
  }
  return head;
}
Calificacion * agregarCalificacion(Calificacion * head, Calificacion * elemento) {
  Calificacion * current = head;
  if(current == NULL) {
    current = elemento;
    return current;
  }

  Calificacion * update = getCalificacion(head, elemento);
  if(update == NULL) {
    current = (Calificacion *)getLast(head, CALIFICACION);
    current->next = elemento;
  } else {
    update->rating = elemento->rating;
  }
  return head;
}
void * getLast(void * head, tipoDeNodo tipo) {
  if(tipo != CALIFICACION) {
    Nodo * current = (Nodo *)head;
    while(current->next != NULL) current = current->next;
    return current;
  } else {
    Calificacion * current = (Calificacion *)head;
    while(current->next != NULL) current = current->next;
    return current;
  }
}
int checkInList(Nodo * head, Nodo * elemento) {
  Nodo * current = head;
  while(current != NULL){
    if(strcmp(current->nombre, elemento->nombre) == 0) return 1;
    current = current->next;
  }
  return 0;
}
Calificacion * getCalificacion(Calificacion * head, Calificacion * elemento) {
  Calificacion * current = head;
  while(current != NULL){
    if(current->usuario == elemento->usuario && current->pelicula == elemento->pelicula) {
      return current;
    }
    current = current->next;
  }
  //printf("\n");
  return NULL;
}
