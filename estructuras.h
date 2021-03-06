#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#define USER_LEARNING 0.01
#define MOVIE_LEARNING 0.001

#define LIM_MIN 0.02

#define N_FEATURES 17
/* Types declarations */
// typedef struct Pu {
//     int idPu;
//     char nombre_usuario[20];
//     float feature_values[17];
//     struct Pu *next;
// }Pu_t;
//
// typedef struct Qi{
//     int idQi;
//     char nombre_pelicula[40];
//     float feature_values[17];
//     struct Qi *next;
// }Qi_t;
// Cambio para que sea una misma estructura
typedef struct Nodo_t{
    int id;
    char nombre[40];
    float feature_values[N_FEATURES];
    struct Nodo_t *next;
}Nodo;

typedef struct Calificacion_t{
    Nodo *usuario;
    Nodo *pelicula;
    float rating;
    struct Calificacion_t *next;
}Calificacion;

typedef enum {
  USUARIO,
  PELICULA,
  CALIFICACION
} tipoDeNodo;

#endif
