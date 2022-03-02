#ifndef DT_H_
#define DT_H_
#include "../implementacion/subject.h"
#include "../implementacion/observer.h"

typedef enum{
    OFENSIVA = 0,
    EQUILIBRADA = 1,
    DEFENSIVA = 2
}Estrategia;

typedef struct _dt{
    char *nombre;

    Estrategia estrategia;
    Estrategia (*getStrategy)(struct _dt *);

    void (*cambiarEstrategia)(struct _dt *, Estrategia *);
    
    Subject * subject;
    void (*addObserver)(struct _dt *, Observer*);
    void (*removeObserver)(struct _dt *, Observer*);
}Dt;

Dt *dt_new(char *);

#endif