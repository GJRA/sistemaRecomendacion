#include "modelo.h"
#include "vista.h"

int main(void) {
    //leerCSV("base.csv");
    Nodo *usuarios = NULL;
    Nodo *peliculas = NULL;
    Nodo *calificaciones = NULL;

    printf("%p\n", usuarios);
    printf("%p\n", peliculas);
    Nodo *temp = (Nodo *)malloc (sizeof (Nodo));
    if(temp == NULL) printf("ERROR\n");
    temp->id = 1; 
    strcpy(temp->nombre,"Simon");
    // temp->feature_values = generarRand();
    usuarios = agregarALista(usuarios, temp, USUARIO);

    printf("%p\n", usuarios);
    printf("%p\n", peliculas);
    temp = (Nodo *)malloc (sizeof (Nodo));
    if(temp == NULL) printf("ERROR\n");
    temp->id = 2;
    strcpy(temp->nombre,"Darian");
    // temp->feature_values = generarRand();
    usuarios = agregarALista(usuarios, temp, USUARIO);

    printf("%p\n", usuarios);
    printf("%p\n", peliculas);
    temp = (Nodo *)malloc (sizeof (Nodo));
    if(temp == NULL) printf("ERROR\n");
    temp->id = 3;
    strcpy(temp->nombre,"Simon");
    // temp->feature_values = generarRand();
    usuarios = agregarALista(usuarios, temp, USUARIO);

    printf("%p\n", usuarios);
    printf("%p\n", peliculas);
    temp = (Nodo *)malloc (sizeof (Nodo));
    if(temp == NULL) printf("ERROR\n");
    temp->id = 1;
    strcpy(temp->nombre,"The Usual Suspects");
    // temp->feature_values = generarRand();
    peliculas = agregarALista(peliculas, temp, PELICULA);

    printf("%p\n", usuarios);
    printf("%p\n", peliculas);
    temp = (Nodo *)malloc (sizeof (Nodo));
    if(temp == NULL) printf("ERROR\n");
    temp->id = 2;
    strcpy(temp->nombre,"El Hoyo");
    // temp->feature_values = generarRand();
    peliculas = agregarALista(peliculas, temp, PELICULA);

    printf("%p\n", usuarios);
    printf("%p\n", peliculas);
    temp = (Nodo *)malloc (sizeof (Nodo));
    if(temp == NULL) printf("ERROR\n");
    temp->id = 3;
    strcpy(temp->nombre,"The Usual Suspects");
    // temp->feature_values = generarRand();
    peliculas = agregarALista(peliculas, temp, PELICULA);

    printf("%p\n", usuarios);
    printf("%p\n", peliculas);
    printLista(usuarios, USUARIO);
    printLista(peliculas, PELICULA);


    return 0;
}
