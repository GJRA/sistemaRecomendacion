#include "controlador.h"

Nodo * agregarUsuario(char * nombre, Nodo * headUsuarios, Calificacion ** headCalificaciones, Nodo * headPeliculas) {
  Nodo * elemento = malloc(sizeof(Nodo));
  elemento->next = NULL;
  strcpy(elemento->nombre, nombre);
  elemento->id = headUsuarios == NULL ? 1 : getLastId(headUsuarios)+1;
  setGetPromedio(elemento->feature_values, headUsuarios);
  int i = 0;
  while (i < 5) {
    Nodo *pelicula = randomMovie(headPeliculas);
    Calificacion * temp = malloc(sizeof(Calificacion));
    temp->pelicula = pelicula;
    temp->usuario = elemento;
    //printNode(temp, CALIFICACION);
    if(getCalificacion(*headCalificaciones, temp) == NULL) {
      printNodeName(pelicula, PELICULA);
      int rating = askUserRating(pelicula->nombre);
      if(rating >= 0 && rating <= 10) {
        *headCalificaciones = calificaPelicula(elemento, pelicula, rating/10.0, *headCalificaciones);
        i++;
      }
    }
    free(temp);
  }
  return agregarALista(headUsuarios, elemento, USUARIO);
}

Nodo * recomendarAmigo(Nodo *headUsuarios,char *nombre){
  float max = 0.0,val=0.0;
  Nodo * amigoRecomendado = NULL;
  Nodo * current = headUsuarios;
  Nodo * usuario = searchInList(headUsuarios,nombre);
  if(usuario!=NULL){
    while(current != NULL){
      if(strcmp(current->nombre,nombre) != 0){
        val =productoPunto(usuario->feature_values,current->feature_values);
        if (val>max){
          amigoRecomendado = current;
          max=val;
        }
      }
      current = current->next;
    }
  }else{
    printf("El usuario: %s no existe en la base de datos, sorry :(\n",nombre);
  }
  return amigoRecomendado;
}

int peliculasParecidas(Nodo *headPeliculas,char *nombre, Nodo *peliculasParecidas[]){
  Nodo * pelicula = searchInList(headPeliculas,nombre);
  if(pelicula!=NULL){
    int i = 0;
    do {
      float max = 0.0,val=0.0;
      Nodo * peliculaParecida = NULL;
      Nodo * current = headPeliculas;
      while(current != NULL){
        if(strcmp(current->nombre,nombre) != 0){
          val =productoPunto(pelicula->feature_values,current->feature_values);
          if (val>max && !contains(peliculasParecidas, current, 3)){
            peliculaParecida = current;
            max=val;
          }
        }
        current = current->next;
      }
      peliculasParecidas[i] = peliculaParecida;
      i++;
    } while(i <= 3);
    return 1;
  }else{
    printf("La pelicula: %s no existe en la base de datos, sorry :(\n",nombre);
    return 0;
  }
}

Nodo * recomendarPelicula(Nodo *headPeliculas,Calificacion *headCalificacion,Nodo *headUsuarios, char *nombre){
  float max = 0.0,val=0.0;
  Nodo * peliRecomendada = NULL;
  Nodo * current = headPeliculas;
  Calificacion * cal = headCalificacion;
  Nodo * usuario = searchInList(headUsuarios,nombre);
  Calificacion *elemCali = malloc (sizeof (Calificacion));
  if(usuario!=NULL){
    elemCali -> usuario = usuario;
    while(current != NULL){
      elemCali -> pelicula = current;
      if(getCalificacion(cal,elemCali)==NULL){
        val =productoPunto(usuario->feature_values,current->feature_values);
        if (val>max){
          peliRecomendada = current;
          max=val;
        }
      }
      current = current->next;
    }
    free(elemCali);
  }else{
    printf("El usuario: %s no existe en la base de datos, sorry :(\n",nombre);
  }
  return peliRecomendada;
}

void entrenarSistema(char *nomFile, Calificacion * calificaciones) {
  // char nomFile2[255];
  // sprintf(nomFile2, "%s%f.csv", nomFile, USER_LEARNING);
  int epoch = 0;
  float errorRms = 100000.0;
  float prevError = errorRms;
  int sameErrorCount = 0;
  // float range = USER_LEARNING/5;
  do {
    errorRms = rms(calificaciones);
    // if(errorRms >= prevError-range && errorRms <= prevError+range) {
    //   sameErrorCount++;
    // } else {
    //   sameErrorCount = 0;
    //   prevError = errorRms;
    // }
    graficaErrorEpochs(nomFile,errorRms,epoch);
    epoch++;
    // printf("Epoch: %d --> error: %f --> count: %d\n", epoch, errorRms, sameErrorCount);
    // if(errorRms >= prevError) {
    //   sameErrorCount++;
    // } else {
    //   sameErrorCount=0;
    // }
    // if(sameErrorCount >= 5) break;
    Calificacion *current = calificaciones;
    int length = getListLength(calificaciones, CALIFICACION);
    int counter = 1;
    while(current != NULL) {
      // printProgress(length, counter, 20);
      entrenar(current->usuario->feature_values, current->pelicula->feature_values, current->rating, USER_LEARNING);
      entrenar(current->pelicula->feature_values, current->usuario->feature_values, current->rating, MOVIE_LEARNING);
      counter++;
      current = current->next;
    }
    // prevError = errorRms;
  // } while (errorRms > LIM_MIN && sameErrorCount < pow(USER_LEARNING, -1));
  } while (errorRms > LIM_MIN);
}

void printReporte(char *fileName, Nodo *usuarios, Nodo *peliculas, Calificacion *calificaciones) {
  FILE *fp;
  fp=fopen(fileName,"w+");
  fprintf(fp, "REPORTE DEL PROGRAMA\n\n");
  printListaFile(fp, usuarios, USUARIO);
  fprintf(fp, "\n");
  printListaFile(fp, peliculas, PELICULA);
  fprintf(fp, "\n");
  printMatrizFile(fp, usuarios, peliculas, calificaciones, 1);
  fclose(fp);
}

void printCSV(char *fileName, Nodo *usuarios, Nodo *peliculas, Calificacion *calificaciones) {
  FILE *fp;
  fp=fopen(fileName,"w+");
  printMatrizFile(fp, usuarios, peliculas, calificaciones, 0);
  fclose(fp);
}
Nodo * agregarPelicula(char * nombre, Nodo * headPeliculas) {
  Nodo * peliculasParecidas[5];
  Nodo * elemento = malloc(sizeof(Nodo));
  elemento->next = NULL;
  strcpy(elemento->nombre, nombre);
  elemento->id = headPeliculas == NULL ? 1 : getLastId(headPeliculas)+1;
  int i = 0;
  while (i < 5) {
    Nodo *peliculas[2];
    Nodo *peli;
    do {
      peli = randomMovie(headPeliculas);
    } while(contains(peliculasParecidas, peli, 5));
    peliculas[0] = peli;
    do {
      do {
        peli = randomMovie(headPeliculas);
      } while(contains(peliculasParecidas, peli, 5));
      peliculas[1] = peli;
    } while(peliculas[0]->nombre==peliculas[1]->nombre);
    int opcion = askMovies(peliculas);
    peliculasParecidas[i] = peliculas[opcion];
    i++;
  }
  promedioPeliculas(elemento->feature_values, peliculasParecidas, 5);
  return agregarALista(headPeliculas, elemento, PELICULA);
}
