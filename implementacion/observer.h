//Suscriptor
#ifndef OBSERVER_H_
#define OBSERVER_H_
#include "subject.h"

typedef struct{
    void * impl;                                                //implementación del jugador                      
    void (*update)(struct Observer *,int , Subject *);          //(this, state, subject)
    void (*impl_update)(void *impl_j,int nose, void*);          //this.impl (impl update jugador)
}Observer;

Observer *observer_new(void *, void (*)(void *, int, void *));  //impl del jug;impl update jugad
void observer_destroy(Observer*);       //Dudando si hacer esto un atr como una dirección void

#endif