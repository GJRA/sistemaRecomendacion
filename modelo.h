#ifndef MODELO_H
#define MODELO_H


// -----------------------------
// Public interface
// -----------------------------

/* Types declarations */
typedef struct Pu{
    int idPu;
    char nombre_usuario[20];
    float feature_values[17];
    Pu_t *next;  
}Pu_t;

typedef struct Qi{
    int idQi;
    char nombre_pelicula[20];
    float feature_values[17];
    Qi_t *next;  
}Qi_t;

typedef struct Calificacion{
    Qi_t *usuario; 
    Pu_t *pelicula; 
    int rating;
    Calificacion_t *next;
}Calificacion_t;

/* Function prototypes */
/**
 * Obtener datos de la matriz general
 * 
 * @param nomFile es el nombre del csv donde se obtendran los datos
 */
void leerCSV(char *nomFile);

/**
 * Crea la grafica Error vs Epochs
 *
 * 
 */
void graficaErrorEpochs();
/**
 * Operacion producto punto entre 2 matrices
 *  
 *
 * @param matriz matriz horizontal
 * @param matriz2 matriz vertical
 * @return el resultado producto punto
 */
int productoPunto(float *matriz, float *matriz2);

/**
 * Operacion resta entre 2 numeros
 *  
 *
 * @param num1 Rating Esperado
 * @param num2 Rating Calculado
 * @return el resultado resta
 */
int error(int num1, int num2);

/**
 * Operacion para obtener rating calculado
 *
 * @param matrizTarget matriz que se actualizara
 * @param matrizReferencia matriz que se neceita en la formula
 * @param rating rating del CSV
 */
double entrenar(float *matrizTarget, float *matrizReferencia, int rating );



#endif
