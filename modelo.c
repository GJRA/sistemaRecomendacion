#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "modelo.h"
#include "estructuras.h"
/* Private types */
static void generarRand(float **valores[17]){
    //float valores[17];
    float val[17];
    srand((unsigned int)time(NULL));
    for(int i = 0; i < 17; i++){
        val[i] = (float)rand()/(float)(RAND_MAX/1);
    }
    strcpy(valores,val);
}

void leerCSV(char *nomFile){
	FILE *file;
	file = fopen(nomFile, "r");
    Pu_t *elemPu=NULL;
    Qi_t *elemQi=NULL;
	int i = 0;
    char line[4098];
    srand((unsigned int)time(NULL));
    while (fgets(line, 4098, file))
    {
        int j = 0;
        const char* tmp = strdup(line);
        char delimitador[] = ",";
        char *token = strtok(tmp, delimitador);
        if(token != NULL){
            while(token != NULL){
                if(i==0){
                    if(j!=0){
                        elemPu = malloc (sizeof (Pu_t));
                        elemPu -> idPu = j-1;
                        strcpy(elemPu -> nombre_usuario,token);
                        generarRand(&elemPu->feature_values);
                        //Primer renglon con usuarios
                        printf("Nombres: ");
                        printf("%s\t",token);
                    }
                }else{
                    if(j == 0){
                        elemQi = malloc (sizeof (Qi_t));
                        elemQi -> idQi = i-1;
                        strcpy(elemQi -> nombre_pelicula,token);
                        generarRand(&elemQi->feature_values);
                        printf("Peli %s\t",token );
                    }else{
                        if(atoi(token)>= 0){
                        Calificacion_t *elemCali = malloc (sizeof (Calificacion_t));
                        elemCali -> usuario = elemPu;
                        elemCali -> pelicula = elemQi;
                        elemCali -> rating = atoi(token);
                        printf("%s\t",token);
                        }
                    }
                    
                }
                j++;
                token = strtok(NULL, delimitador);
            }
        }
        free(tmp);
        i++;
    }
}











