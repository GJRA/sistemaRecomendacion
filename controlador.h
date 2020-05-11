#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "estructuras.h"
#include "modelo.h"
#include "vista.h"
// -----------------------------
// Public interface
// -----------------------------

/* Function prototypes */

Nodo * agregarUsuario(char * nombre, Nodo * headUsuarios, Calificacion ** headCalificaciones, Nodo * headPeliculas);
#endif
