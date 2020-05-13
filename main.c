#include "modelo.h"
#include "vista.h"
#include "controlador.h"

int main(void) {

    Nodo *usuarios = NULL;
    Nodo *peliculas = NULL;
    Calificacion *calificaciones = NULL;

    srand((unsigned) time(NULL));
    printf("Leyendo Base de Datos\n");
    leerCSV("base.csv", &usuarios, &peliculas, &calificaciones);
    printf("Base de Datos Leida\n");
    printf("Entrenando el Sistema\n");
    entrenarSistema("errorEpoch.csv", calificaciones);
    printf("Sistema Entrenado\n");
    printf("USUARIOS: %d\n", getListLength(usuarios, USUARIO));
    printf("PELICULAS: %d\n", getListLength(peliculas, PELICULA));
    printf("CALIFICACIONES: %d\n", getListLength(calificaciones, CALIFICACION));

    char ch;
    scanf(" %c", &ch);

    Nodo * yo = searchInList(usuarios, "Simon");
    Nodo * amigo =recomendarAmigo(usuarios,"Simon");
    Nodo *peli = recomendarPelicula(peliculas,calificaciones,usuarios,"Simon");

    printf("Yo:\n");
    printNode(yo, USUARIO);

    printf("Amigo:\n");
    printNode(amigo, USUARIO);

    printf("Pelicula:\n");
    printNode(peli, PELICULA);

    scanf(" %c", &ch);

    agregarPelicula("Prueba", peliculas);

    printf("USUARIOS: %d\n", getListLength(usuarios, USUARIO));
    printf("PELICULAS: %d\n", getListLength(peliculas, PELICULA));
    printf("CALIFICACIONES: %d\n", getListLength(calificaciones, CALIFICACION));

    yo = searchInList(peliculas, "Prueba");
    Nodo *parecidas[3] = {NULL, NULL, NULL};
    peliculasParecidas(peliculas, "Joker", parecidas);
    // peli = recomendarPelicula(peliculas,calificaciones,usuarios,"Prueba");

    printf("Pelicula:\n");
    printNode(yo, PELICULA);

    printf("Parecidas:\n");
    for(int i = 0; i <3; i++) printNode(parecidas[i], PELICULA);

    printReporte("reporte.txt", usuarios, peliculas, calificaciones);
    printCSV("base2.csv", usuarios, peliculas, calificaciones);
    return 0;
}
