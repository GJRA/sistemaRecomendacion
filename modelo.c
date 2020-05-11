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
int getLastId(Nodo *head) {
  Nodo * elemento = getLast(head, USUARIO);
  return ((Nodo *) elemento)->id;
}
Nodo * randomMovie(Nodo *head) {
  int length = getListLength(head, PELICULA);
  int random = rand() % length;
  Nodo * pelicula= (Nodo *)getByPosition(head, random, PELICULA);
  return pelicula;
}
int getListLength(void *head, tipoDeNodo tipo) {
  void * current = head;
  int count = 0;
  while(current != NULL) {
    if(tipo == CALIFICACION) {
      current = ((Calificacion *)current)->next;
    } else {
      current = ((Nodo *)current)->next;
    }
    count++;
  }
  return count;
}

void * getByPosition(void * head, int pos, tipoDeNodo tipo) {
  if(pos >= getListLength(head, tipo)) return NULL;
  int i = 0;
  void * current = head;
  while (i < pos) {
    if(tipo == CALIFICACION) {
      current = ((Calificacion *)current)->next;
    } else {
      current = ((Nodo *)current)->next;
    }
    i++;
  }
  return current;
}

Calificacion * calificaPelicula(Nodo * usuario, Nodo * pelicula, int rating, Calificacion * calificaciones) {
  Calificacion *elemCali = malloc (sizeof (Calificacion));
  if(elemCali == NULL) printf("ERROR crear calificacion\n");
  elemCali -> usuario = usuario;
  elemCali -> pelicula = pelicula;
  elemCali -> rating = rating;
  elemCali->next = NULL;
  // printf("%s\t",token);
  return agregarCalificacion(calificaciones, elemCali);
}

float productoPunto(float *matriz , float *matriz2){
    float sum= 0.0;
    for(int i = 0; i <17;i++){
        sum=sum+matriz[i]*matriz2[i];
    }
    return sum;
}

float error(float num1, float num2){
    return (num1-num2);
}

float rms(Nodo *headUsuarios, Nodo *headPeliculas, Calificacion *headCalificacion){
    float rm=0.0,sum=0.0,cont=1.0;
    Calificacion * currentC = headCalificacion;
    Nodo *currentP = headPeliculas;
    Nodo *currentU = headUsuarios;
    while(currentC != NULL){
      while(currentP != NULL){
        while (currentU != NULL){
          Calificacion *elem= malloc (sizeof (Calificacion));
          elem -> usuario = currentU;
          elem -> pelicula = currentP;
          currentU = currentU->next;
          if(getCalificacion(currentC,elem)!=NULL){
            rm=productoPunto(currentP->feature_values,currentU->feature_values);
            sum=sum+pow(error(currentC->rating,rm),2);
            cont++;
            currentU = currentU -> next;
          }else{
            currentU = currentU ->next;
          }
        }
        currentU = headUsuarios;
        currentP = currentP->next;
      }
        currentC = currentC->next;  
    }
    rm=sqrt(sum/cont);
    printf("El rms del 1er epoch es: %f\n",rm);
    return rm;
}

void graficaErrorEpochs(char *nomFile, float rms, int epoch){
  printf("\n Creating %s.csv file",nomFile);
  //nomFile=strcat(nomFile,".csv");
  FILE *fp;
  int i,j;
  
  printf("filename:%s\n");
  fp=fopen(nomFile,"w+");
  fprintf(fp,"%f,%d\n",rms,epoch);
  fclose(fp);
  printf("\n %sfile created",nomFile); 
}