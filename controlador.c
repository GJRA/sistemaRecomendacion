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

Nodo * recomendarPelicula(Nodo *headPeliculas,Calificacion *headCalificacion,Nodo *headUsuarios, char *nombre){
  float max = 0.0,val=0.0;
  Nodo * peliRecomendada = NULL;
  Nodo * current = headPeliculas;
  Calificacion * cal = headCalificacion;
  Nodo * usuario = searchInList(headUsuarios,nombre);
  Calificacion *elemCali = malloc (sizeof (Calificacion));
  if(usuario!=NULL){
    while(current != NULL){  
      elemCali -> usuario = usuario;
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
  }else{
    printf("El usuario: %s no existe en la base de datos, sorry :(\n",nombre);
  }
  return peliRecomendada;
}
