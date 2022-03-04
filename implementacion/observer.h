//SUSCRIPTOR
#ifndef OBSERVER_H_
#define OBSERVER_H_

typedef struct _observer{
    void (*destroyOb)(struct _observer *);                      //(this)
    void * impl;                                                //implementación del jugador                      
    void (*update)(struct _observer *,int , void *);            //(this, state, subject)
    void (*impl_update)(void *,int, void*);                     //this.impl (impl update jugador)
}Observer;

//Observer constructor
Observer *observer_new(void *, void (*)(void *, int, void *));  //impl del jug;impl update jugad

#endif