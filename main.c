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

    int opc =0;
    char nombre[40];
    while(opc!=12){
        opc = menu();
        switch(opc){
            case 1 :
                entrenarSistema("errorEpoch.csv", calificaciones);
            break;
            case 2: 
                printf("Escribe el nombre de un usuario: ");
                scanf(" %s", &nombre);
                Nodo * amigo = recomendarAmigo(usuarios,nombre);
                printNode(amigo, USUARIO);
            break;
            case 3:
                printf("Escribe el nombre de un usuario: ");
                scanf(" %s", &nombre);
                Nodo *peli = recomendarPelicula(peliculas,calificaciones,usuarios,nombre);
                printNode(peli, PELICULA);
            break;
            case 4: 
                printf("imprimir rating de las peliculas de un usuario: ");
            break;
            case 5: 
                printf("Escribe el nombre de una pelicula: ");
                scanf(" %s", &nombre);
                printFeature(nombre,peliculas);
            break;
            case 6: 
                printf("Escribe el nombre de un usuario: ");
                scanf(" %s", &nombre);
                printFeature(nombre,usuarios);
            break;
            case 7: 
                printf("imprimir rating de una pelicula de todos los usuarios");
            break;
            case 8: 
                printReporte("reporte.txt", usuarios, peliculas, calificaciones);
            break;
            case 9: 
                printf("Escribe el nombre \n");
                scanf("%s",&nombre);
                agregarUsuario(nombre, usuarios, &calificaciones, peliculas);
            break;
            case 10: 
                printf("Agregar pelicula \n");
            break;
            case 11: 
                printf("Calificar pelicula");
            break;
            case 12: 
                printf("Adios vaquero!\n");
            break;
            default:
                printf("Opcion no valido\n");
            break;
        }
    }

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
