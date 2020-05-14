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
    printf("Sistema Entrenado \n");
    printf("USUARIOS: %d\n", getListLength(usuarios, USUARIO));
    printf("PELICULAS: %d\n", getListLength(peliculas, PELICULA));
    printf("CALIFICACIONES: %d\n", getListLength(calificaciones, CALIFICACION));

    limpiar(usuarios);
    limpiar(peliculas);

    int opc =0;
    char nombre[255],nom[255];
    int rat;
    Nodo *usr = NULL;
    Nodo *pel = NULL;
    Nodo *usuario = NULL;
    Nodo *pelicula = NULL;
    while(opc!=13){
        opc = menu();
        switch(opc){
            case 1 :
                entrenarSistema("errorEpoch.csv", calificaciones);
            break;
            case 2:
                printf("Escribe el nombre de un usuario: ");
                scanf(" %[^\n]s", nombre);
                usuario = recomendarAmigo(usuarios,nombre);
                printf("Te recomendamos que seas amigo de %s\n", usuario->nombre);
            break;
            case 3:
                printf("Escribe el nombre de un usuario: ");
                scanf(" %[^\n]s", nombre);
                pelicula = recomendarPelicula(peliculas,calificaciones,usuarios,nombre);
                printf("Te recomendamos que veas %s\n", pelicula->nombre);
            break;
            case 4:
              do {
                printf("Escribe el nombre del usuario: ");
                scanf(" %[^\n]s", nombre);
                usuario = searchInList(usuarios, nombre);
                if(usuario == NULL) printf("No existe el usuario\n");
              } while(usuario == NULL);
              imprimirCalificaciones(calificaciones, usuario, USUARIO);
            break;
            case 5:
                printf("Escribe el nombre de una pelicula: ");
                scanf(" %[^\n]s", nombre);
                pelicula = searchInList(peliculas, nombre);
                printNode(pelicula,PELICULA);
            break;
            case 6:
                printf("Escribe el nombre de un usuario: ");
                scanf(" %[^\n]s", nombre);
                usuario = searchInList(usuarios, nombre);
                printNode(usuario,USUARIO);
            break;
            case 7:
              do {
                printf("Escribe el nombre de la pelicula: ");
                scanf(" %[^\n]s", nombre);
                pelicula = searchInList(peliculas, nombre);
                if(pelicula == NULL) printf("No existe la pelicula\n");
              } while(pelicula == NULL);
              imprimirCalificaciones(calificaciones, pelicula, PELICULA);
            break;
            case 8:
                printReporte("reporte.txt", usuarios, peliculas, calificaciones);
                printf("Reporte Generado\n");
            break;
            case 9:
                printf("Escribe el nombre: ");
                scanf(" %[^\n]s",nombre);
                agregarUsuario(nombre, usuarios, &calificaciones, peliculas);
            break;
            case 10:
                printf("Escribe el nombre: ");
                scanf(" %[^\n]s",nombre);
                agregarPelicula(nombre,peliculas);
            break;
            case 11:
              do {
                printf("Escribe el nombre del usuario que realizara la calificacion\n");
                scanf(" %[^\n]s",nombre);
                usr = searchInList(usuarios, nombre);
                if(usr == NULL) printf("El usuario no existe\n");
              } while(usr == NULL);
              do {
                printf("Escribe el nombre de la pelicula a calificar\n");
                scanf(" %[^\n]s",nom);
                pel = searchInList(peliculas, nom);
                if(pel == NULL) printf("La pelicula no existe\n");
              } while(pel == NULL);
                do {
                  rat = -1;
                  printf("Escribe la calificacion (0-10 entero): ");
                  scanf(" %d",&rat);
                  if(rat < 0 || rat > 10) printf("Numero afuera de rango\n");
                } while(rat < 0 || rat > 10);
                float rat2 = (float)rat / 10.0;
                calificaPelicula(usr, pel, rat2, calificaciones);
            break;
            case 12:
                printf("Escribe el nombre de la pelicula para buscar su peliculas parecidas\n");
                scanf(" %[^\n]s",nom);
                Nodo *parecidas[3] = {NULL, NULL, NULL};
                if(peliculasParecidas(peliculas, nom, parecidas)) {
                  printf("Parecidas:\n");
                  for(int i = 0; i <3; i++) printf("Pelicula: %s\n",parecidas[i]->nombre);
                }
            break;
            case 13:
                printCSV("base.csv", usuarios, peliculas, calificaciones);
                printReporte("reporte.txt", usuarios, peliculas, calificaciones);
                printf("Adios vaquero!\n");
            break;
            default:
                printf("Opcion no valida\n");
            break;
        }
    }


    // char ch;
    // scanf(" %c", &ch);
    //
    // Nodo * yo = searchInList(usuarios, "Simon");
    // Nodo * amigo =recomendarAmigo(usuarios,"Simon");
    // Nodo *peli = recomendarPelicula(peliculas,calificaciones,usuarios,"Simon");
    //
    // printf("Yo:\n");
    // printNode(yo, USUARIO);
    //
    // printf("Amigo:\n");
    // printNode(amigo, USUARIO);
    //
    // printf("Pelicula:\n");
    // printNode(peli, PELICULA);
    //
    // scanf(" %c", &ch);
    //
    // agregarPelicula("Prueba", peliculas);
    //
    // printf("USUARIOS: %d\n", getListLength(usuarios, USUARIO));
    // printf("PELICULAS: %d\n", getListLength(peliculas, PELICULA));
    // printf("CALIFICACIONES: %d\n", getListLength(calificaciones, CALIFICACION));
    //
    // yo = searchInList(peliculas, "Prueba");
    // Nodo *parecidas[3] = {NULL, NULL, NULL};
    // peliculasParecidas(peliculas, "Joker", parecidas);
    // // peli = recomendarPelicula(peliculas,calificaciones,usuarios,"Prueba");
    //
    // printf("Pelicula:\n");
    // printNode(yo, PELICULA);
    //
    // printf("Parecidas:\n");
    // for(int i = 0; i <3; i++) printNode(parecidas[i], PELICULA);
    //
    // printReporte("reporte.txt", usuarios, peliculas, calificaciones);
    // printCSV("base2.csv", usuarios, peliculas, calificaciones);
    return 0;
}
