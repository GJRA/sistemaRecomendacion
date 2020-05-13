#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void escribirEnCSV(char nombreDeArchivo[50], char (*usuarios)[5][10], char (*peliculas)[5][10],  int (*calificaciones)[5][5]);

int main()
{
    char peliculas[5][10] = {"Hola", "Hola1", "Hola2", "Hola3", "Hola4"};
    char usuarios[5][10] = {"Darian", "Ricardo", "Serch", "Gaby", "Simon"};
    int calificaciones[5][5] = {
        {-1, 1, 2, 3, 4},
        {-1, 1, 2, 3, 4},
        {-1,1,2,3,4},
        {-1,1,2,3,4},
        {-1,2,3,4,5}
    };
    escribirEnCSV("archivo.csv", &usuarios, &peliculas, &calificaciones);
}

void escribirEnCSV(char nombreDeArchivo[50], char (*usuarios)[5][10], char (*peliculas)[5][10],  int (*calificaciones)[5][5]) {
    FILE *archivo;
    archivo = fopen(nombreDeArchivo,"wt");
    size_t peliculas_length = sizeof(*peliculas) / sizeof((*peliculas)[0]);
    size_t cal_length = sizeof(*calificaciones) / sizeof((*calificaciones)[0]);
    fprintf(archivo, "%s", "Peliculas");
    size_t new_usr_length = sizeof(*usuarios)/ sizeof((*usuarios)[0]);
    for (int y=0 ; y< new_usr_length ; y++) {
        fprintf(archivo,",%s", (*usuarios)[y]);
    }
    fprintf(archivo,"\n");
    for (int i=0 ; i< peliculas_length ; i++) {
        fprintf(archivo,"%s", (*peliculas)[i]);
        for (int j=0 ; j< cal_length ; j++) {
            fprintf(archivo,",%d", (*calificaciones)[i][j]);
        }
        fprintf(archivo,"\n");
    }
    fclose(archivo);
}

