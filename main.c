#include "modelo.h"
#include "vista.h"
#include "controlador.h"

int main(void) {

    Nodo *usuarios = NULL;
    Nodo *peliculas = NULL;
    Calificacion *calificaciones = NULL;

    srand((unsigned) time(NULL));

    leerCSV("base.csv", &usuarios, &peliculas, &calificaciones);

    entrenarSistema("errorEpoch.csv", calificaciones);

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

    agregarUsuario("Prueba", usuarios, &calificaciones, peliculas);

    printf("USUARIOS: %d\n", getListLength(usuarios, USUARIO));
    printf("PELICULAS: %d\n", getListLength(peliculas, PELICULA));
    printf("CALIFICACIONES: %d\n", getListLength(calificaciones, CALIFICACION));

    yo = searchInList(usuarios, "Prueba");
    amigo =recomendarAmigo(usuarios,"Prueba");
    peli = recomendarPelicula(peliculas,calificaciones,usuarios,"Prueba");

    printf("Yo:\n");
    printNode(yo, USUARIO);

    printf("Amigo:\n");
    printNode(amigo, USUARIO);

    printf("Pelicula:\n");
    printNode(peli, PELICULA);

    printReporte("reporte.txt", usuarios, peliculas, calificaciones);
    return 0;
}
