#include "modelo.h"
/* Private types */
// static void generarRand(float **valores[17]){
//     //float valores[17];
//     float val[17];
//     srand((unsigned int)time(NULL));
//     for(int i = 0; i < 17; i++){
//         val[i] = (float)rand()/(float)(RAND_MAX/1);
//     }
//     strcpy(valores,val);
// }


// void leerCSV(char *nomFile){
// 	FILE *file;
// 	file = fopen(nomFile, "r");
//
// 	int i = 0;
//     char line[4098];
//     srand((unsigned int)time(NULL));
//     while (fgets(line, 4098, file))
//     {
//         int j = 0;
//         const char* tmp = strdup(line);
//         char delimitador[] = ",";
//         char *token = strtok(tmp, delimitador);
//         if(token != NULL){
//             while(token != NULL){
//                 if(i==0){
//                     if(j!=0){
//                         Pu_t *elemPu = malloc (sizeof (Pu_t));
//                         elemPu -> idPu = j-1;
//                         strcpy(elemPu -> nombre_usuario,token);
//                         generarRand(&elemPu->feature_values);
//                         //Primer renglon con usuarios
//                         printf("Nombres: ");
//                         printf("%s\t",token);
//                     }
//                 }else{
//                     if(j == 0){
//                         Qi_t *elemQi = malloc (sizeof (Qi_t));
//                         elemQi -> idQi = i-1;
//                         strcpy(elemQi -> nombre_pelicula,token);
//                         generarRand(&elemQi->feature_values);
//                         printf("Peli %s\t",token );
//                     }else{
//                         Calificacion_t *elemCali = malloc (sizeof (Calificacion_t));
//                         //elemCali -> usuario = elemPu;
//                         //elemCali -> pelicula = elemQi;
//                         elemCali -> rating = atoi(token);
//                         printf("%s\t",token);
//                     }
//
//                 }
//                 j++;
//                 token = strtok(NULL, delimitador);
//             }
//         }
//         free(tmp);
//         i++;
//     }
// }

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
    printf("B\n");
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
    printf("%s = %s?\n", current->nombre, elemento->nombre);
    if(strcmp(current->nombre, elemento->nombre) == 0) return 1;
    current = current->next;
  }
  return 0;
}
Calificacion * getCalificacion(Calificacion * head, Calificacion * elemento) {
  Calificacion * current = head;
  while(current != NULL){
    if(current->usuario == elemento->usuario && current->pelicula == elemento->pelicula) break;
    current = current->next;
  }
  return current;
}
