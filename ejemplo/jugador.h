#ifndef JUGADOR_H_
#define JUGADOR_H_
#include "../implementacion/subject.h"
#include "../implementacion/observer.h"
#include "dt.h"

typedef enum _ubi{
    ARRIBA = 0,
    MEDIO = 1,
    ABAJO = 2
}Ubi;

typedef struct _jugador{
    char *nombre;
    Ubi ubicacion;
    Ubi (*getUbicacion)(struct _jugador *);
    void (*firmarContrato)(struct _jugador *, Dt*);
    void (*destroy)(struct _jugador *);
    Observer * observer;
}Jugador;

Jugador *jugador_new(char *, int);
#endif