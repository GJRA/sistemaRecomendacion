#include "modelo.h"
/* Private types */
void generarRand(float *val){
    //float valores[17];
    for(int i = 0; i < N_FEATURES; i++){
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
                        generarRand(elemPu->feature_values);
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
                        generarRand(elemQi->feature_values);
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
                        elemCali -> rating = atoi(token)/10.0;
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
Nodo * searchInList(Nodo * head, char *nombre) {
  Nodo * current = head;
  while(current != NULL){
    if(strcmp(current->nombre,nombre) == 0) return current;
    current = current->next;
  }
  return NULL;
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

Calificacion * calificaPelicula(Nodo * usuario, Nodo * pelicula, float rating, Calificacion * calificaciones) {
  Calificacion *elemCali = malloc (sizeof (Calificacion));
  if(elemCali == NULL) printf("ERROR crear calificacion\n");
  elemCali -> usuario = usuario;
  elemCali -> pelicula = pelicula;
  elemCali -> rating = rating;
  elemCali->next = NULL;
  entrenar(usuario->feature_values, pelicula->feature_values, rating, USER_LEARNING);
  entrenar(pelicula->feature_values, usuario->feature_values, rating, MOVIE_LEARNING);
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

float rms(Calificacion *headCalificacion){
    int length = getListLength(headCalificacion, CALIFICACION);
    Calificacion *current = headCalificacion;
    float sum = 0.0;
    while (current != NULL) {
      float producto = productoPunto(current->usuario->feature_values, current->pelicula->feature_values);
      sum += pow(error(current->rating, producto), 2);
      current = current->next;
    }
    float promedio = sum / length;
    return sqrt(promedio);
}

void graficaErrorEpochs(char *nomFile, float rms, int epoch){
  FILE *fp;
  int i,j;
  if(epoch==1){
    fp=fopen(nomFile,"w+");
  }else{
    fp=fopen(nomFile,"a+");
  }
  fprintf(fp,"%f,%d\n",rms,epoch);
  fclose(fp);
}

void setGetPromedio(float *val, Nodo * head) {
  for(int i = 0; i < N_FEATURES; i++) {
    float sum = 0.0;
    int count = getListLength(head, USUARIO);
    Nodo * current = head;
    while (current != NULL) {
      sum += current->feature_values[i];
      current = current->next;
    }
    val[i] = sum/count;
  }
}

void entrenar(float *target, float *referencia, float rating, float learning_rate) {
  float punto = productoPunto(target, referencia);
  float errorF = error(rating, punto);
  for(int i = 0; i < N_FEATURES; i++) {
    target[i] = target[i]+learning_rate*errorF*referencia[i];
  }
}

void printMatrizFile(FILE *fp, Nodo *usuarios, Nodo *peliculas, Calificacion *calificaciones, int reporte) {
  if(reporte) {
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
  } else {
    fprintf(fp, "Nombre Pelicula");
    Nodo *current = usuarios;
    while (current != NULL) {
      fprintf(fp, ",%s ", current->nombre);
      current = current->next;
    }
    fprintf(fp, "\n");
    current = peliculas;
    while (current != NULL) {
      fprintf(fp, "%s", current->nombre);
      Nodo *currentUser = usuarios;
      while(currentUser != NULL) {
        Calificacion * elemento = malloc(sizeof(Calificacion));
        elemento->usuario = currentUser;
        elemento->pelicula = current;
        Calificacion *calif = getCalificacion(calificaciones, elemento);
        int rating = calif == NULL ? -1 : (calif->rating)*10;
        fprintf(fp, ",%d ", rating);
        currentUser = currentUser->next;
        free(elemento);
      }
      fprintf(fp, "\n");
      current = current->next;
    }
  }
}

void printListaFile(FILE *fp, void *head, tipoDeNodo tipo) {
  if (tipo != CALIFICACION) {
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
  if(tipo != CALIFICACION) {
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
