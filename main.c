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

    int opc =0;
    char nombre[40],nom[40];
    float rat;
    while(opc<13){
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
                printf("Escribe el nombre \n");
                scanf("%s",&nombre);
                agregarPelicula(nombre,peliculas);
            break;
            case 11: 
                printf("Escribe el nombre del usuario que realizara la calificacion\n");
                scanf("%s",&nombre);
                printf("Escribe el nombre de la pelicula a calificar\n");
                scanf("%s",&nom);
                Nodo * usr = searchInList(usuarios, nombre);
                Nodo * pel = searchInList(peliculas, nom);
                printf("Escribe la calificacion modificada \n");
                scanf("%f",rat);
                calificaPelicula(usr, pel, rat,calificaciones);
            break;
            case 12: 
                printf("Escribe el nombre de la pelicula para buscar su peliculas parecidas\n");
                scanf("%s",&nom);
                Nodo *parecidas[3] = {NULL, NULL, NULL};
                peliculasParecidas(peliculas, nom, parecidas);
                printf("Parecidas:\n");
                for(int i = 0; i <3; i++) printNode(parecidas[i], PELICULA);
            break;
            case 13: 
                printCSV("base2.csv", usuarios, peliculas, calificaciones);
                printReporte("reporte.txt", usuarios, peliculas, calificaciones);
                printf("Adios vaquero!\n");
            break;
            default:
                printf("Opcion no valida\n");
            break;
        }
    }

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
