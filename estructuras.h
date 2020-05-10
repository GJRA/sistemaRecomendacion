#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

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

#endif
