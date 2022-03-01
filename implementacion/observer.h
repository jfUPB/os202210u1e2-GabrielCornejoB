//Suscriptor
#ifndef OBSERVER_H_
#define OBSERVER_H_
#include "subject.h"

typedef void (*update)(struct observer *, subject *);

typedef struct{
    update update;
}observer;

observer observer_new();
void observer_ctor(observer*);
void observer_destroy(observer*);

#endif