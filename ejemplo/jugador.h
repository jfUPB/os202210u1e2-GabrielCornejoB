#ifndef JUGADOR_H_
#define JUGADOR_H_
#include "../implementacion/subject.h"
#include "../implementacion/observer.h"

typedef enum{
    ARRIBA = 0,
    MEDIO = 1,
    ABAJO = 2
}Ubi;

typedef struct{
    char *nombre;
    Ubi *ubicacion;
    Ubi (*getUbicacion)(struct Jugador *);
    //void (*chutar)(void *);
    //void (*pasar)(void *);
    Observer * observer;
}Jugador;

Jugador *jugador_new(char *, Ubi);
#endif