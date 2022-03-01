#ifndef JUGADOR_H_
#define JUGADOR_H_
#include "../implementacion/subject.h"
#include "../implementacion/observer.h"

typedef void (*chutar)(void *);
typedef void (*pasar)(void *);

typedef struct{
    char *nombre;
    chutar chutar;
    pasar pasar;
    observer * observer;
}jugador;

jugador *jugador_new();
void jugador_ctor(jugador *, char *);

#endif