#ifndef DT_H_
#define DT_H_
#include "../implementacion/subject.h"
#include "../implementacion/observer.h"

typedef enum _dtEvent{
    DAR_ORDEN
}DtEvent;

typedef struct _dt{
    char *nombre;
    void (*destroy)(struct _dt*);

    DtEvent event;
    DtEvent (*getEvent)(struct _dt *);

    void (*darOrden)(struct _dt *);      //Es como un set

    Subject * subject;
    void (*addObserver)(struct _dt *, Observer*);
    void (*removeObserver)(struct _dt *, Observer*);
}Dt;

Dt *dt_new(char *);

#endif