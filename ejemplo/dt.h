#ifndef DT_H_
#define DT_H_
#include "../implementacion/subject.h"
#include "../implementacion/observer.h"

typedef enum{
    OFENSIVA = 0,
    EQUILIBRADA = 1,
    DEFENSIVA = 2
}Estrategia;

typedef struct{
    char *nombre;
    Estrategia estrategia;
    Estrategia (*cambiarEstrategia)(struct Dt);
    Subject * subject;
}Dt;

#endif