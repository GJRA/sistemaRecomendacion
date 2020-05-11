#include "modelo.h"
#include "vista.h"

int main(void) {

    Nodo *usuarios = NULL;
    Nodo *peliculas = NULL;
    Calificacion *calificaciones = NULL;

    srand((unsigned) time(NULL));

    leerCSV("base.csv", &usuarios, &peliculas, &calificaciones);

    // printf("%p\n", usuarios);
    // printf("%p\n", peliculas);
    // Nodo *temp = (Nodo *)malloc (sizeof (Nodo));
    // if(temp == NULL) printf("ERROR\n");
    // temp->id = 1;
    // strcpy(temp->nombre,"Simon");
    // // temp->feature_values = generarRand();
    // usuarios = agregarALista(usuarios, temp, USUARIO);
    //
    // printf("%p\n", usuarios);
    // printf("%p\n", peliculas);
    // temp = (Nodo *)malloc (sizeof (Nodo));
    // if(temp == NULL) printf("ERROR\n");
    // temp->id = 2;
    // strcpy(temp->nombre,"Darian");
    // // temp->feature_values = generarRand();
    // usuarios = agregarALista(usuarios, temp, USUARIO);
    //
    // printf("%p\n", usuarios);
    // printf("%p\n", peliculas);
    // temp = (Nodo *)malloc (sizeof (Nodo));
    // if(temp == NULL) printf("ERROR\n");
    // temp->id = 3;
    // strcpy(temp->nombre,"Simon");
    // // temp->feature_values = generarRand();
    // usuarios = agregarALista(usuarios, temp, USUARIO);
    //
    // printf("%p\n", usuarios);
    // printf("%p\n", peliculas);
    // temp = (Nodo *)malloc (sizeof (Nodo));
    // if(temp == NULL) printf("ERROR\n");
    // temp->id = 1;
    // strcpy(temp->nombre,"The Usual Suspects");
    // // temp->feature_values = generarRand();
    // peliculas = agregarALista(peliculas, temp, PELICULA);
    //
    // printf("%p\n", usuarios);
    // printf("%p\n", peliculas);
    // temp = (Nodo *)malloc (sizeof (Nodo));
    // if(temp == NULL) printf("ERROR\n");
    // temp->id = 2;
    // strcpy(temp->nombre,"El Hoyo");
    // // temp->feature_values = generarRand();
    // peliculas = agregarALista(peliculas, temp, PELICULA);
    //
    // printf("%p\n", usuarios);
    // printf("%p\n", peliculas);
    // temp = (Nodo *)malloc (sizeof (Nodo));
    // if(temp == NULL) printf("ERROR\n");
    // temp->id = 3;
    // strcpy(temp->nombre,"The Usual Suspects");
    // // temp->feature_values = generarRand();
    // peliculas = agregarALista(peliculas, temp, PELICULA);
    //
    // printf("%p\n", usuarios);
    // printf("%p\n", peliculas);
    printf("USUARIOS\n");
    printLista(usuarios, USUARIO);
    printf("PELICULAS\n");
    printLista(peliculas, PELICULA);
    printf("CALIFICACIONES\n");
    printLista(calificaciones, CALIFICACION);


    return 0;
}
